/*
	3376. 파도반 수열 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWD3Y27q3QIDFAUZ&categoryId=AWD3Y27q3QIDFAUZ&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <cstring>
#include <numeric>
#include <sstream>

using namespace std;

long long int func(int n) {
	long long int arr[101] = { 0, };
	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = arr[5] = 2;

	if (n >= 6) {
		for (int i = 6; i <= n; i++)
			arr[i] = arr[i - 1] + arr[i - 5];
	}
	return arr[n];
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
		scanf("%d", &n);

		//출력
		printf("#%d %lld", line++,func(n));
		printf("\n");
		t--;
	}

	return 0;
}