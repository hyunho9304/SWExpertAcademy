/*
	2817. 부분 수열의 합 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7IzvG6EksDFAXB&categoryId=AV7IzvG6EksDFAXB&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <cstring>
#include <numeric>
#include <sstream>

using namespace std;

int func(int arr[], int n, int k) {
	int ans = 0;
	bool flag;

	while (k > 0) {

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
		cin >> n >> k;
		
		int *arr = new int[n + 1];
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		
		//출력
		printf("#%d %d", line++,func(arr,n,k));
		printf("\n");
		t--;
	}

	return 0;
}