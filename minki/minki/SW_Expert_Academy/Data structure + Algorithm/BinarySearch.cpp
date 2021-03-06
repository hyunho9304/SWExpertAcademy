/*
	이진 검색 알고리즘(binary search algorithm)은 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘이며,
	처음 중간의 값을 임의의 값으로 선택하여, 그 값과 찾고자 하는 값의 크고 작음을 비교하는 방식을 채택하고 있다.
	처음 선택한 중앙값이 만약 찾는 값보다 크면 그 값은 새로운 최고값이 되며, 작으면 그 값은 새로운 최하값이 된다.
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <string>
#include <numeric>
#include <sstream>

#define MAX_M 100

int T;    // # of test case
int M;    // # of element in array
int N;    // # of numbers to search
int arr[MAX_M];

void binarySearch(int *arr, int low, int high, int target) {
	int mid;
	if (low > high) {
		printf("-1 ");
		return;
	}

	mid = (low + high) / 2;
	if (target < arr[mid])
		binarySearch(arr, low, mid - 1, target);
	else if (target > arr[mid])
		binarySearch(arr, mid + 1, high, target);
	else {
		printf("%d ", mid);
		return;
	}
}

int main()
{
	int targetValue;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d %d", &M, &N);

		for (int i = 0; i < M; i++)
		{
			scanf("%d", &arr[i]);
		}

		printf("#%d ", test_case);

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &targetValue);
			binarySearch(arr, 0, M - 1, targetValue);
		}
		
		printf("\n");
	}

	return 0;
}