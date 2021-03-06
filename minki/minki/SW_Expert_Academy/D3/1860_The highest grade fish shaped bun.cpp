/*
	1860. 진기의 최고급 붕어빵 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LsaaqDzYDFAXc&categoryId=AV5LsaaqDzYDFAXc&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <cstring>
#include <numeric>
#include <sstream>

using namespace std;

string func(int arr[], int n, int m, int k) {
	string ans[2] = { "Possible", "Impossible" };
	bool flag=true;
	int cnt = 0, sum = 0 , i = 0;

	for (int i = 0; i < n; i++) {
		//손님찾을때까지 만든 붕어빵의 양
		while (cnt != arr[i]){
			cnt++;
			if (cnt % m == 0)
				sum += k;
		}

		//손님있으니 붕어빵 하나 뺌
		sum--;
			
		//손님보다 붕어빵이 적으면 미션 실패
		if (sum < 0) {
			flag = false;
			break;
		}
	}

	return flag ? ans[0] : ans[1];
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
		scanf("%d %d %d", &n, &m, &k);

		int *arr = new int[n];

		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		sort(arr, arr + n);

		//출력
		printf("#%d %s", line++,func(arr,n,m,k).c_str());
		printf("\n");
		t--;
	}

	return 0;
}