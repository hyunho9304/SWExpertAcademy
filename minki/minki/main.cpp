/*
	Stack은 한 쪽 끝에서만 자료를 넣거나 뺄 수 있는 선형 구조(LIFO - Last In First Out)로 데이터를 저장하는 형식을 말한다.	
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

#define MAX_N 100

int front;
int rear;
int queue[MAX_N];

void queueInit(void) {
	front = 0;
	rear = 0;
}

void queueEnqueue(int value) {

}

int queueIsEmpty() {

}

int queueDequeue(int *value) {

}

int main()
{
	int T;
	int N;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);

		queueInit();
		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			queueEnqueue(value);
			printf("setValue");
		}

		printf("#%d ", test_case);

		while (!queueIsEmpty())
		{
			int value;
			if (queueDequeue(&value) == 1)
			{
				printf("%d ", value);
			}
		}
		printf("\n");
	}

	return 0;
}