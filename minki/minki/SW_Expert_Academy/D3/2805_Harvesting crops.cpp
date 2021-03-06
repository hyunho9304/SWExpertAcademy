/*
	2805. 농작물 수확하기 D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GLXqKAWYDFAXB&categoryId=AV7GLXqKAWYDFAXB&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, number;
	bool flag, flag2;
	vector<int> vec, temp_vec, ans_vec;
	vector<vector<int>> vec_vec;
	string str, temp_str;

	cin >> t;

	int arr[50][50];

	while (t > 0) {
		//입력    
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < n; j++)
				arr[i][j] = str[j] - '0';
		}

		ans = 0;

		for (int i = 0; i < n; i++) {
			//n이면 0 ~ n/2까지
			if (i < (n + 1) / 2) {
				for (int j = 0; j < i * 2 + 1; j++)
					ans += arr[j + n / 2 - i][i];
			}
			// 2/n ~ n까지
			else {
				for (int j = 1; j < n * 2 - i * 2; j++)
					ans += arr[j + i - (n + 1) / 2][i];
			}
		}

		printf("#%d %d\n", line++, ans);
		vec.clear();
		t--;
	}

	return 0;
}