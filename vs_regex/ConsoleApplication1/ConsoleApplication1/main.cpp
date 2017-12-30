#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include "ReTree.h"
#include "Nfa.h"
#define ll long long
using namespace std;
const int maxn = 10000;
int main() {
	//freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
	//Re_tree re_tr("(a|b)*cde");
	//re_tr.print();
	nfa a("ab*(c*|(de)*)");
	a.print();
	return 0;
}
