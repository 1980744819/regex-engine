#pragma once
#ifndef _RE_TREE_NODE
#define _RE_TREE_NODE
using namespace std;

enum CharKind {
	elem,
	Or,
	Connect,
	Closure
};
class Re_tree_node
{
public:
	Re_tree_node(CharKind kind,char c,Re_tree_node *p1,Re_tree_node *p2);
	~Re_tree_node();

	CharKind char_kind;
	char ch;
	Re_tree_node *lchild, *rchild;
};

Re_tree_node::Re_tree_node(CharKind kind, char c, Re_tree_node *p1, Re_tree_node *p2)
{
	this->char_kind = kind;
	this->ch = c;
	this->lchild = p1;
	this->rchild = p2;
}

Re_tree_node::~Re_tree_node()
{
}


#endif