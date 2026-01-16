#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[3];
int dp_mx[3] = { 0, };
int dp_mn[3] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 입력되는 숫자는 0 ~ 9
	cin >> n;

	int temp0, temp1, temp2;

	for (int i = 0; i < n; i++) {
		cin >> arr[0] >> arr[1] >> arr[2];

		temp0 = dp_mx[0];
		temp1 = dp_mx[1];
		temp2 = dp_mx[2];

		dp_mx[0] = max(temp0, temp1) + arr[0];
		dp_mx[1] = max({ temp0,temp1,temp2 }) + arr[1];
		dp_mx[2] = max(temp1, temp2) + arr[2];

		temp0 = dp_mn[0];
		temp1 = dp_mn[1];
		temp2 = dp_mn[2];

		dp_mn[0] = min(temp0, temp1) + arr[0];
		dp_mn[1] = min({ temp0,temp1,temp2 }) + arr[1];
		dp_mn[2] = min(temp1, temp2) + arr[2];

	}

	int mx_value = max({ dp_mx[0], dp_mx[1], dp_mx[2] });
	int mn_value = min({ dp_mn[0], dp_mn[1], dp_mn[2] });
	
	cout << mx_value << " " << mn_value;

}