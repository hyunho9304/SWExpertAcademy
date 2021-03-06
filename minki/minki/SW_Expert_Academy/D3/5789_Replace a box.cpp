/*
	5789. 현주의 상자 바꾸기 -D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWYygN36Qn8DFAVm&categoryId=AWYygN36Qn8DFAVm&categoryType=CODE
*/

#include <iostream>
#include <vector>   
#include <algorithm> 
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, index, q, l, r;
	vector<int> vec, temp_vec;
	string str, temp_str;
	vector<string> str_vec, ans_vec;

	cin >> t;

	while (t > 0) {
		int arr[1000] = { 0, };

		//입력
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= q; i++) {
			scanf("%d %d", &l, &r);
			for (int j = l; j <= r; j++)
				arr[j - 1] = i;
		}

		//출력
		cout << "#" << line++ << " ";
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		cout << endl;
		t--;
	}
	return 0;
}