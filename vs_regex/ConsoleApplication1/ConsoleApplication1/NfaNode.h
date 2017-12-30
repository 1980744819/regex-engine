#pragma once
#ifndef NFA_NODE
#define NFA_NODE


#include "NfaEdge.h"
#include<vector>


using namespace std;

class nfa_edge;

class nfa_node
{
public:
	nfa_node();
	~nfa_node();
	//nfa_edge * head;
	int status_num;
	bool is_visit;
	vector<nfa_edge *> edges;
	//void add_edge(nfa_edge *p);
	void set_status_num(int num);
	int get_status_num();
	
};
int nfa_node::get_status_num() {
	return status_num;
}
void nfa_node::set_status_num(int num) {
	this->status_num = num;
}
/*void nfa_node::add_edge(nfa_edge *p) {
	edges.push_back(p);
}*/
nfa_node::nfa_node()
{
	status_num = -1;
	is_visit = false;
	edges.clear();
}

nfa_node::~nfa_node()
{
}


#endif