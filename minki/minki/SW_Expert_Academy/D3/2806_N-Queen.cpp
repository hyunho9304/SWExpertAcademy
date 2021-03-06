/*
	2806. N-Queen -D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GKs06AU0DFAXB
*/

#include <iostream>
#include <vector>   
#include <algorithm> 
#include <string>
#include <sstream>

using namespace std;

int N;
int col[15];
//	col 순서는 위에서 아래로
//	예를 들어 N = 4일 때 정답 하나는 col ={1,3,0,2}
int result = 0;

bool promising(int i) {
	for (int j = 0; j < i; j++)
		//새로운 퀸과 기존퀸이 같은 행에 있을경우 , 대각선에 있을 경우
		if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
			return false;

	return true;
}

void N_queen(int i) {
	if (i == N)
		result += 1;
	else {
		for (int j = 0; j < N; j++) {
			col[i] = j;
			if (promising(i))
				N_queen(i + 1);
		}
	}
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
		cin >> N;

		N_queen(0);

		cout << "#" << line++ << " " << result << endl;
		result = 0;
		t--;
	}
	return 0;
}

/*
방법 2
bool col[16],inc[31],decr[31];

void solve(int r) {
	if (r > N) {
		result++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!col[i] && !inc[r + i] && !decr[N + (r - i) + 1]) {
			col[i] = inc[r + i] = decr[N + (r - i) + 1] = true;
			solve(r + 1);
			col[i] = inc[r + i] = decr[N + (r - i) + 1] = false;
		}
	}
}

main(){
	solve(1);
}

*/