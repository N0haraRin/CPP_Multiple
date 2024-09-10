#include "global.h"

int vn; // variable num
int cn; // clause num
short* times = nullptr;

int main()
{
	string suffix_read = ".cnf";
	string suffix_output = ".res";
	string fn1;
	cout << "Please enter the filename (enter quit to quit) : ";
	cin >> fn1;
	while (fn1 != "quit")
	{
		string read = fn1 + suffix_read;
		ClsNode* cnf = read_cnf(read, times);
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
			ofstream fp(output);
			fp << "s" << " " << "-1" << endl;
			fp << "v" << endl;
			fp << "t" << " " << (end - start);
		}
		cout << "Duration : " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
		cout << "Please enter the filename (enter quit to quit) : ";
		cin >> fn1;
	}
	cout << "GoodBye!";
	/**/
	return 0;
}