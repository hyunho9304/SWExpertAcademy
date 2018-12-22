/*
	계수정렬(counting sort)는 항목들의 순서를 결정하기 위해 
	집합에 각 항목이 몇 개씩 있는지 세는 작업을 하면서 정렬하는 알고리즘이다
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <string>
#include <numeric>
#include <sstream>


#define MAX_N 100
#define MAX_DIGIT 10

int N;  // # of data set
int arr[MAX_N];
int cnt[MAX_DIGIT];
int sortedArr[MAX_N];

void calculateDigitNumber() {
	//cnt[i] 엔 i의 개수
	for (int i = 0; i < N; i++) {
		cnt[arr[i]]++;
	}
	//개수를 누적
	for (int i = 1; i < MAX_DIGIT; i++)
	{
		cnt[i] = cnt[i] + cnt[i - 1];
	}
}

void executeCountingSort() {
	for (int i = N - 1; i >= 0; i--)
	{
		//arr[i] : 정렬안된 배열 , cnt[arr[i]] - 1: i의 개수가 누적된 배열
		sortedArr[cnt[arr[i]] - 1] = arr[i];
	}
}

int main()
{
	int T;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}

		// initialize
		for (int i = 1; i < MAX_DIGIT; i++)
		{
			cnt[i] = 0;
		}
		calculateDigitNumber();
		executeCountingSort();

		//print the sorted digits
		printf("#%d ", test_case);
		for (int i = 0; i < N; i++)
		{
			printf("%d ", sortedArr[i]);
		}
		printf("\n");
	}

	return 0;
}