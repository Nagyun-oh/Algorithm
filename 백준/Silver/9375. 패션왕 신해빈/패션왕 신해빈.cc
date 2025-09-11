#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<string, int> wear;
int T, n;
void init();
void solve();

void init()
{
	string w_name;
	string w_type;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> w_name >> w_type;

			if (wear.find(w_type) == wear.end())
			{
				wear[w_type] = 1;
			}
			else
			{
				wear[w_type]++;
			}
		}

		solve();
	}

}

// 옷의 종류가 서로 달라야 옷끼리 호환가능
// 확통 개념을 떠올리니까 문제풀이법이 이해가 됐다. (해당 옷입는 경우 + 안입는경우) * (해당 옷입는 경우 + 안입는경우)...
void solve()
{
	/*for (auto& p : wear)
	{
		cout << "옷 이름 : " << p.first << ", 옷 종류 : " << p.second << '\n';
	}*/

	int count = 1;
	for (auto&x : wear)
	{
		count *= (x.second) + 1;
	}

	count -= 1; // 다 안입는  1가지 경우 빼기
	

	cout << count << '\n';

	wear.clear();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

}