#include "global.h"

extern int vn;
extern int cn;

ClsNode* read_cnf(string& filename, short*& times)
{
	ifstream fp(filename);
	if (!fp)
	{
		cout << "Can't open file" << " " << filename << "!";
		exit(0);
	}
	char explanation[105]; // read c-started sentence
	char ch; // read the first letter
	fp >> ch;
	while (ch == 'c')
	{
		fp.getline(explanation, 105);
		fp >> ch;
	}
	string format; // read "cnf"
	if (ch == 'p')
	{
		fp >> format >> vn >> cn;
	}
	times = new short[vn + 1];
	memset(times, 0, sizeof(short) * (vn + 1));
	int clscnt = 0; // count clsnum
	ClsNode* CHead, * CTail;
	CHead = CTail = nullptr;
	int abs = 0;
	while (cn != clscnt)
	{
		VarNode* VHead, * VTail;
		VHead = VTail = nullptr;
		int var;
		int varnum = 0; // variable num
		fp >> var;
		while (var)
		{
			abs = var > 0 ? var : -var;
			times[abs]++;
			if (!VHead)
			{
				VHead = new VarNode;
				VHead->var = var;
				VHead->next = NULL;
				VTail = VHead;
			}
			else
			{
				VTail->next = new VarNode;
				VTail->next->var = var;
				VTail->next->next = nullptr;
				VTail = VTail->next;
			}
			varnum++;
			fp >> var;
		}
		if (!CHead)
		{
			CHead = new ClsNode;
			CHead->ClsHead = VHead;
			CHead->varnum = varnum;
			CHead->down = nullptr;
			CTail = CHead;
		}
		else
		{
			CTail->down = new ClsNode;
			CTail->down->ClsHead = VHead;
			CTail->down->varnum = varnum;
			CTail->down->down = nullptr;
			CTail = CTail->down;
		}
		clscnt++;
	}
	// test 
	
	ClsNode* current = CHead;
	cout << "Successfully read file " << filename << "!" << endl;
	cout << "Content is followed : " << endl;
	while (current)
	{
		cout << current->varnum << " : ";
		VarNode* cur = current->ClsHead;
		while (cur)
		{
			cout << cur->var;
			cout << " ";
			cur = cur->next;
		}
		cout << endl;
		current = current->down;
	}/*
	*/
	fp.close();
	return CHead;
}