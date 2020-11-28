#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int w, h, ret = 0;
	cin >> w >> h;
	vector<vector<int>> v;
	v.resize(w);
	for (auto& e : v)
		e.resize(h, 1);

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (v[i][j] == 1)
			{
				ret++;
				// 标记不能放蛋糕的位置 
				if ((i + 2) < w)
					v[i + 2][j] = 0;

				if ((j + 2) < h)
					v[i][j + 2] = 0;
			}
		}
	}
	cout << ret << endl;
	return 0;
}
