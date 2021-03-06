/*
	6057. 그래프의 삼각형 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWbHcWd6AFcDFAV0&categoryId=AWbHcWd6AFcDFAV0&categoryType=CODE#
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <cstring>
#include <numeric>
#include <sstream>

using namespace std;

int func(int **arr, int n) {
	int ans = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (arr[i][j]) {
				for (int k = j + 1; k < n; k++) {
					if (arr[i][k] && arr[j][k]) {
						ans++;
					}
				}
			}
		}
	}

	return ans;
}

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, index;
	bool flag;
	vector<int> vec, temp_vec;
	string str, temp_str;
	vector<string> str_vec, ans_vec;

	cin >> t;

	while (t > 0) {
		//입력
		cin >> n >> m;
		
		int** arr = new int*[n];
		int x, y;

		for (int i = 0; i < n ; i++) {
			arr[i] = new int[n ];
			memset(arr[i], 0, sizeof(int)*(n));
		}

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			arr[x - 1][y - 1] = arr[y - 1][x - 1] = 1;
		}

		//출력
		printf("#%d %d", line++,func(arr,n));
		printf("\n");
		t--;
	}

	return 0;
}