/*
	4789. 성공적인 공연 기획 -D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWS2dSgKA8MDFAVT&categoryId=AWS2dSgKA8MDFAVT&categoryType=CODE
*/

#include <iostream>
#include <vector>   
#include <algorithm> 
#include <string>
#include <sstream>

using namespace std;

int func(string str) {
	//count = 손 드는 사람의 수 , sum = 손 들어야하는 사람의 수
	int count = 0, sum = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '0') {
			if (count < i) {
				sum += i - count;
				count += i - count;
			}
			count += str[i] - '0';
		}
	}

	return sum;
}

int main()
{
	int t, ans, line = 1, len, m, k, temp, sum, max, cnt, index;
	bool flag;
	vector<int> vec, temp_vec;
	string str, temp_str;
	vector<string> str_vec, ans_vec;

	cin >> t;

	while (t > 0) {
		//입력
		cin >> str;

		cout << "#" << line++ << " " << func(str) << endl;
		t--;
	}
	return 0;
}