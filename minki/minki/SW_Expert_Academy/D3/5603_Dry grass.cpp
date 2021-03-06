/*
	5603. Dry grass -D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXGEbd6cjMDFAUo&categoryId=AWXGEbd6cjMDFAUo&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

int ads(int arr[]) {
	for(int i = 0;i<2;i++)
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
		cin >> n;
		ans = 0;
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			vec.push_back(temp);
			sum += temp;
		}

		sort(vec.begin(), vec.end());
		
		int* arr = new int[n];

		arr[0] = 4;
		arr[1] = 2;
		
		printf("size : %d\n", sizeof(*arr));
		
		int left = 0;
		int right = n - 1;
		int avg = sum / n;

		while (vec[left] != vec[right]) {
			temp = avg - vec[left];
			ans += temp;
			vec[left++] = avg;
			while (vec[right] - temp < avg) {
				temp -= vec[right] - avg;
				vec[right--] = avg;
			}
			vec[right] -= temp;
		}

		cout << "#" << line++ << " " << ans << endl;
		vec.clear();
		t--;
	}

	return 0;
}