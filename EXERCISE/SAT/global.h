#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <algorithm>
using namespace std;

typedef struct vnode{
	int var;
	struct vnode* next;
} VarNode; // Variable Node

typedef struct cnode{
	int varnum;
	struct vnode* ClsHead;
	struct cnode* down;
} ClsNode; // Clause Node

ClsNode* read_cnf(string& filename, short*& times); // read .cnf file
int findSC(ClsNode* cnf);
void removeCls(ClsNode*& cnf, ClsNode* target);
void removeSC(ClsNode*& cnf, int var);
void removeVar(ClsNode*& cnf, int var);
bool hasEmpty(ClsNode* cnf);
ClsNode* addVar(ClsNode* cnf, int var);
ClsNode* copy(ClsNode* cnf);
int findMax(short* times);
bool DPLL(ClsNode* cnf, short ans[]);

#endif

