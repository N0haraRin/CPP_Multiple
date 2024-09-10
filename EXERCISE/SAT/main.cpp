#include "global.h"

int vn; // variable num
int cn; // clause num

int main()
{
	string suffix_read = ".cnf";
	string suffix_output = ".res";
	string fn1 = "1";
	string usat = "(unsatisfied)";
	string read = "1.cnf";
	ClsNode* cnf = read_cnf(read);
	short* ans = new short[vn + 1];
	memset(ans, 0, sizeof(short) * (vn + 1));
	/*
	for (int i = 0; i < vn + 1; i++)
	{
		cout << ans[i] << endl;
	}
	*/
	clock_t start = clock();
	bool res = DPLL(cnf, ans);
	clock_t end = clock();
	if (res)
	{
		string output = fn1 + suffix_output;
		ofstream fp(output);
		fp << "s" << " " << "1" << endl;
		fp << "v" << " ";
		for (int i = 1; i < vn + 1; i++)
		{
			if (ans[i] > 0)
			{
				fp << i << " ";
			}
			else
			{
				fp << -i << " ";
			}
		}
		fp << endl;
		fp << "t" << " " << (end - start);
	}
	else
	{
		string output = fn1 + suffix_output;
		fstream fp(output);
		fp << "s" << " " << "-1" << endl;
		fp << "v" << endl;
		fp << "t" << " " << (end - start);
	}
	cout << "Duration : " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	
	/**/
	return 0;
}