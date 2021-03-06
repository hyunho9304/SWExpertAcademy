/*
	1873. 상호의 배틀필드 -D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LyE7KD2ADFAXc&categoryId=AV5LyE7KD2ADFAXc&categoryType=CODE
*/

#include <iostream>
#include <vector>   
#include <algorithm> 
#include <string>
#include <sstream>

using namespace std;

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
		cin >> cnt >> temp;

		for (int i = 0; i < cnt; i++) {
			cin >> temp_str;
			str_vec.push_back(temp_str);
		}
		cin >> temp >> temp_str;

		index = 0;
		// 전차 찾기
		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < str_vec[i].size(); j++)
				//상좌하우
				if (str_vec[i][j] == 'v' || str_vec[i][j] == '^' || str_vec[i][j] == '<' || str_vec[i][j] == '>') {
					n = i;
					m = j;
					if (str_vec[i][j] == '^')
						index = 1;
					else if (str_vec[i][j] == '<')
						index = 2;
					else if (str_vec[i][j] == 'v')
						index = 3;
					else if (str_vec[i][j] == '>')
						index = 4;
					break;
				}
			if (index)
				break;
		}

		//입력 처리
		for (int i = 0; i < temp_str.length(); i++) {
			if (temp_str[i] == 'U') {
				index = 1;
				str_vec[n][m] = '^';
				if (n - 1 >= 0) {
					if (str_vec[n - 1][m] == '.') {
						str_vec[n - 1][m] = '^';
						str_vec[n][m] = '.';
						n -= 1;
					}
				}
			}
			else if (temp_str[i] == 'L') {
				index = 2;
				str_vec[n][m] = '<';
				if (m - 1 >= 0) {
					if (str_vec[n][m - 1] == '.') {
						str_vec[n][m - 1] = '<';
						str_vec[n][m] = '.';
						m -= 1;
					}
				}
			}
			else if (temp_str[i] == 'D') {
				index = 3;
				str_vec[n][m] = 'v';
				if (n + 1 < cnt) {
					if (str_vec[n + 1][m] == '.') {
						str_vec[n + 1][m] = 'v';
						str_vec[n][m] = '.';
						n += 1;
					}
				}
			}
			else if (temp_str[i] == 'R') {
				index = 4;
				str_vec[n][m] = '>';
				if (m + 1 < str_vec[n].size()) {
					if (str_vec[n][m + 1] == '.') {
						str_vec[n][m + 1] = '>';
						str_vec[n][m] = '.';
						m += 1;
					}
				}
			}
			else if (temp_str[i] == 'S') {
				//상
				if (index == 1) {
					for (int i = n - 1; i >= 0; i--) {
						if (str_vec[i][m] == '#')
							break;
						else if (str_vec[i][m] == '*') {
							str_vec[i][m] = '.';
							break;
						}
					}
				}
				//좌
				else if (index == 2) {
					for (int i = m - 1; i >= 0; i--) {
						if (str_vec[n][i] == '#')
							break;
						else if (str_vec[n][i] == '*') {
							str_vec[n][i] = '.';
							break;
						}
					}
				}
				//하
				else if (index == 3) {
					for (int i = n + 1; i < cnt; i++) {
						if (str_vec[i][m] == '#')
							break;
						else if (str_vec[i][m] == '*') {
							str_vec[i][m] = '.';
							break;
						}
					}
				}
				//우
				else if (index == 4) {
					for (int i = m + 1; i < str_vec[n].length(); i++) {
						if (str_vec[n][i] == '#')
							break;
						else if (str_vec[n][i] == '*') {
							str_vec[n][i] = '.';
							break;
						}
					}
				}
			}
		}

		//출력
		cout << "#" << line++ << " ";
		for (int i = 0; i < cnt; i++)
			cout << str_vec[i] << endl;
		str_vec.clear();
		t--;
	}
	return 0;
}