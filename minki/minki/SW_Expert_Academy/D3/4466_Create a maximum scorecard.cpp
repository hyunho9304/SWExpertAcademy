/*
	4466. 최대 성적표 만들기 D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWOUfCJ6qVMDFAWg&categoryId=AWOUfCJ6qVMDFAWg&categoryType=CODE&&&
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

	while (t > 0) {
		//입력
		cin >> n >> k;
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			vec.push_back(temp);
		}

		sort(vec.rbegin(), vec.rend());

		ans = 0;
		for (int i = 0; i < k; i++)
			ans += vec[i];

		printf("#%d %d\n", line++, ans);
		vec.clear();
		t--;
	}

	return 0;
}