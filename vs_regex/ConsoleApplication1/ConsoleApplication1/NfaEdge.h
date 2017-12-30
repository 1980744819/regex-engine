#pragma once
#ifndef NFA_EDGE
#define NFA_EDGE
#include "NfaNode.h"
using namespace std;

class nfa_node;

class nfa_edge
{
public:
	nfa_edge();
	~nfa_edge();
	nfa_edge(char c, nfa_node *f, nfa_node* t);
	nfa_node * from, *to;
	char ch;
	int status_num;
	bool is_visit;
};
nfa_edge::nfa_edge(char c, nfa_node *f, nfa_node * t) {
	from = f;
	to = t;
	ch = c;
	status_num = -1;
	is_visit = false;
}
nfa_edge::nfa_edge()
{
	this->from = nullptr;
	this->to = nullptr;
	this->ch = '\0';
	this->status_num = -1;
	is_visit = false;
}

nfa_edge::~nfa_edge()
{
}

#endif