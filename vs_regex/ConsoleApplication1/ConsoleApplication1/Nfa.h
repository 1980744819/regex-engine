#pragma once
#ifndef NFA_H
#define NFA_H
#include "NfaEdge.h"
#include "NfaNode.h"
#include "ReTree.h"
#include "ReTreeNode.h"
#include "NfaPoint.h"
using namespace std;


class nfa
{
public:
	nfa();
	~nfa();
	nfa(string str);
	nfa_point * create_nfa(Re_tree_node * root);
	nfa_point * create_nfa_node(Re_tree_node *p);
	void print();
	void set_num(nfa_node *p);
private:
	Re_tree *retree;
	nfa_node *start, *end;
	int edge_num,node_num;
	void dfs_print(nfa_node *p);
};
void nfa::dfs_print(nfa_node *p) {
	if (p->is_visit==false)
	{
		p->is_visit = true;
		for (int i=0;i<p->edges.size();i++)
		{
			printf("%d %c %d\n", p->edges[i]->from->status_num, p->edges[i]->ch == '\0' ? 'x' : p->edges[i]->ch, p->edges[i]->to->status_num);
			dfs_print(p->edges[i]->to);
		}
		//p->is_visit = false;
	}
	/*for (int i = 0; i < p->edges.size(); i++) {
		if (p->edges[i]->is_visit == false);
		{
			p->edges[i]->is_visit = true;
			printf("%d %c %d\n", p->edges[i]->from->status_num, p->edges[i]->ch == '\0' ? 'x' : p->edges[i]->ch, p->edges[i]->to->status_num);
			dfs_print(p->edges[i]->to);
			p->edges[i]->is_visit = false;
		}
	}*/
}
void nfa::print() {
	dfs_print(start);
}
void nfa::set_num(nfa_node *p) {
	if (p->status_num == -1) {
		p->status_num = node_num++;
		for (int i = 0; i < p->edges.size(); i++) {
			if (p->edges[i]->status_num == -1)
			{
				p->edges[i]->status_num = edge_num++;
				set_num(p->edges[i]->to);
			}
		}
	}
}

nfa::nfa(string str)  {
	this->retree = new Re_tree(str);
	Re_tree_node * root = retree->get_root();
	nfa_point *p=create_nfa(root);
	start = p->start;
	end = p->end;
	edge_num = 0;
	node_num = 0;
	set_num(p->start);
}
nfa_point * nfa::create_nfa_node(Re_tree_node *p) {
	nfa_node *a, *b;
	nfa_edge *edge;
	nfa_point *tmp;
	a = new nfa_node();
	b = new nfa_node();
	edge = new nfa_edge(p->ch,a,b);
	tmp = new nfa_point();
	//a->add_edge(edge);
	a->edges.push_back(edge);
	tmp->start = a;
	tmp->end = b;
	return tmp;
}
nfa_point * nfa::create_nfa(Re_tree_node *p) {
	if (p->char_kind==elem)
	{
		nfa_point *tmp = create_nfa_node(p);
		//dfs_print(tmp->start);
		//printf("\n");
		return tmp;
	}
	else if (p->char_kind==Or)
	{
		nfa_point *p1=create_nfa(p->lchild);
		nfa_point *p2 = create_nfa(p->rchild);
		nfa_node *a, *b;
		nfa_edge *e1, *e2, *e3, *e4;
		nfa_point *tmp = new nfa_point();
		a = new nfa_node();
		b = new nfa_node();
		e1 = new nfa_edge('\0',a,p1->start);
		e2 = new nfa_edge('\0',a,p2->start);
		e3 = new nfa_edge('\0',p1->end,b);
		e4 = new nfa_edge('\0',p2->end,b);
		//a->add_edge(e1);
		a->edges.push_back(e1);
		//a->add_edge(e2);
		a->edges.push_back(e2);
		//p1->end->add_edge(e3);
		p1->end->edges.push_back(e3);
		//p2->end->add_edge(e4);
		p2->end->edges.push_back(e4);
		tmp->start = a;
		tmp->end = b;
		//dfs_print(tmp->start);
		//printf("\n");
		return tmp;

	}
	else if (p->char_kind == Connect) {
		nfa_point *p1 = create_nfa(p->lchild);
		nfa_point *p2 = create_nfa(p->rchild);
		nfa_point *tmp = new nfa_point();
		nfa_edge *e = new nfa_edge('\0', p1->end, p2->start);
		//p1->end->add_edge(e);
		p1->end->edges.push_back(e);
		tmp->start = p1->start;
		tmp->end = p2->end;
		//dfs_print(tmp->start);
		//printf("\n");
		return tmp;
	}
	else if(p->char_kind==Closure)
	{
		nfa_point *p1;
		if (p->lchild!=nullptr)
		{
			p1 = create_nfa(p->lchild);
		}
		else {
			p1 = create_nfa(p->rchild);
		}
		nfa_node *a, *b;
		nfa_edge *e1, *e2, *e3, *e4;
		nfa_point *tmp = new nfa_point();
		a = new nfa_node();
		b = new nfa_node();
		e1 = new nfa_edge('\0', p1->end, p1->start);
		e2 = new nfa_edge('\0', a, p1->start);
		e3 = new nfa_edge('\0', p1->end, b);
		e4 = new nfa_edge('\0', a, b);
		//a->add_edge(e4);
		a->edges.push_back(e4);
		//a->add_edge(e2);
		a->edges.push_back(e2);
		//p1->end->add_edge(e1);
		p1->end->edges.push_back(e1);
		//p1->end->add_edge(e3);
		p1->end->edges.push_back(e3);
		tmp->start = a;
		tmp->end = b;
		//dfs_print(tmp->start);
		//printf("\n");
		return tmp;
	}
	else
	{
		return nullptr;
	}
}
nfa::nfa()
{
}

nfa::~nfa()
{
}


#endif
