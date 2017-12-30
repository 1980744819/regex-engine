#pragma once
#ifndef NFA_POINT
#define NFA_POINT
//#include "ReTreeNode.h"
#include "NfaNode.h"

using namespace std;

class nfa_point
{
public:
	nfa_point();
	~nfa_point();
	nfa_point(nfa_node *start, nfa_node * end);
	nfa_node *start, *end;
};

nfa_point::nfa_point(nfa_node *start, nfa_node * end) {
	start = start;
	end = end;
}
nfa_point::nfa_point()
{
	start = nullptr;
	end = nullptr;
}

nfa_point::~nfa_point()
{
}

#endif