#pragma once
#ifndef RE_TREE
#define RE_TREE

#include "ReTreeNode.h"
#include <cstdio>
#include <string>
//#include <>
using namespace std;

class Re_tree
{
public:
	Re_tree(string str);
	~Re_tree();

	Re_tree_node *root;
	string exp;
	char current_char;
	int pos;
	char get_next_char();
	void to_re_tree();
	Re_tree_node *parse_exp();
	Re_tree_node *parse_A();
	Re_tree_node *parse_B();
	Re_tree_node *parse_C();
	Re_tree_node *get_root();
	void print();
	void pre_print_tree(Re_tree_node * p);
	void last_print_tree(Re_tree_node *p);
};

void Re_tree::print() {
	pre_print_tree(root);
	printf("\n");
	last_print_tree(root);
	printf("\n");
}
void Re_tree::pre_print_tree(Re_tree_node *p) {
	if (p != nullptr) {
		printf("%c ", p->ch);
		pre_print_tree(p->lchild);
		pre_print_tree(p->rchild);
	}
}
void Re_tree::last_print_tree(Re_tree_node *p) {
	if (p != nullptr) {
		last_print_tree(p->lchild);
		last_print_tree(p->rchild);
		printf("%c ", p->ch);
	}
}
Re_tree_node * Re_tree::get_root() {
	return root;
}
Re_tree::Re_tree(string str)
{
	this->exp = str;
	root = nullptr;
	current_char = '\0';
	pos = -1;
	to_re_tree();
	print();
}
void Re_tree::to_re_tree() {
	current_char = get_next_char();
	if (current_char=='\0')
	{
		return;
	}
	root=parse_exp();
}
Re_tree_node * Re_tree::parse_exp() {
	Re_tree_node *t = parse_A();
	while (current_char=='|')
	{
		current_char = get_next_char();
		Re_tree_node *p = parse_A();
		t = new Re_tree_node(Or, '|', t, p);
	}
	return t;
}
Re_tree_node * Re_tree::parse_A() {
	Re_tree_node *t = parse_B();
	if (current_char=='\0')
	{
		return t;
	}
	while (current_char=='('||isalpha(current_char))
	{
		Re_tree_node *p = parse_B();
		t = new Re_tree_node(Connect, '+', t, p);

	}
	return t;
}
Re_tree_node * Re_tree::parse_B() {
	Re_tree_node *t = parse_C();
	if (current_char=='\0')
	{
		return t;
	}
	while (current_char == '*') {
		current_char = get_next_char();
		t = new Re_tree_node(Closure, '*', t, nullptr);
	}
	return t;
}
Re_tree_node * Re_tree::parse_C() {
	Re_tree_node *t = nullptr;
	if (current_char=='(')
	{
		current_char = get_next_char();
		t = parse_exp();
		current_char = get_next_char();
	}
	else
	{
		t = new Re_tree_node(elem, current_char, nullptr, nullptr);
		current_char = get_next_char();
	}
	return t;
}
char Re_tree::get_next_char() {
	pos++;
	return exp[pos];
}

Re_tree::~Re_tree()
{
}

#endif