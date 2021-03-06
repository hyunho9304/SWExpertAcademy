/*
	1493. 수의 새로운 연산 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV2b-QGqADMBBASw&categoryId=AV2b-QGqADMBBASw&categoryType=CODE#
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

int arr[350][350];

pair<int,int> fun1(int n) {
	pair<int,int> ans;
	int cnt , gap;
	arr[0][1] = 1;

	for (int i = 1;; i++) {
		arr[0][i + 1] = arr[0][i] + i;
		if (arr[0][i + 1] > n) {
			cnt = i;
			break;
		}
	}

	gap = n - arr[0][cnt];

	ans.first = cnt - gap;
	ans.second = gap + 1;

	return ans;
}

int fun2(int n,int m) {
	int ans = 0 ,cnt;
	arr[0][1] = 1;

	for (int i = 1; i < n + m; i++) {
		arr[0][i + 1] = arr[0][i] + i;
		cnt = i;
	}

	ans = arr[0][cnt] + m - 1;

	return ans;
}

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt,index;
	bool flag;
	vector<int> vec, temp_vec;
	string str, temp_str;
	vector<string> str_vec,ans_vec;
	
	cin >> t;

	while (t > 0) {
		//입력
		cin >> n >> m;
		
		pair<int, int> ans1,ans2;
		ans1 = fun1(n);
		ans2 = fun1(m);

		printf("#%d %d\n", line++,fun2(ans1.first + ans2.first, ans1.second + ans2.second));
		t--;
	}

	return 0;
}