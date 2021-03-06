/*
	parametric search는 어떤 알고리즘으로 해를 바로 구해내는 것이 아니고
	임의의 값을 던지고 맞는지 확인해가며 해를 구하는 방법이다.
	Optimization Problem을 Binary Search + YES/NO Problem (결정 문제)으로 바꾸어 푸는 방법
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <string>
#include <numeric>
#include <sstream>

#define MAX_RIBBON 100

int K, N;
int low, high, mid, numRibbonTape, max;
int sizeRibbonTape[MAX_RIBBON];

void search() {
	mid = low + (high - low) / 2;
	numRibbonTape = 0;

	for (int i = 0; i < K; i++)
		numRibbonTape += (sizeRibbonTape[i] / mid);

	if (numRibbonTape >= N){
		low = mid + 1;
		if (max < mid)
			max = mid;
	}
	else {
		high = mid - 1;
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		low = 1;
		high = 0;
		max -= 1;

		scanf("%d %d", &K, &N);

		for (int i = 0; i < K; i++) {
			scanf("%d", &sizeRibbonTape[i]);
			if (high < sizeRibbonTape[i])
				high = sizeRibbonTape[i];
		}
		while (low <= high)
			search();
		printf("#%d %d\n", test_case, max);
	}

	return 0;
}