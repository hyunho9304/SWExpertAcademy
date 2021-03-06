/*
	3975. 승률 비교하기 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIX_iFqjg4DFAVH&categoryId=AWIX_iFqjg4DFAVH&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>
#include <cstring>

using namespace std;

int main()
{
	int t, line = 1, len, n, m, k, temp, sum, max, number;
	bool flag, flag2;
	vector<int> vec, temp_vec, ans_vec;
	vector<vector<int>> vec_vec;
	string str, temp_str;

	cin >> t;

	string ans[3] = { "ALICE", "BOB", "DRAW" };

	while (t > 0) {
		//입력    
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		
		if (a / (float)b > c / (float)d)
			str = ans[0];
		else if (a / (float)b < c / (float)d)
			str = ans[1];
		else
			str = ans[2];

		//출력
		printf("#%d %s\n", line++, str.c_str());
		t--;
	}

	return 0;
}