/*
	Hash table은 키를 값에 매핑할 수 있는 구조인, 연관 배열 추가에 사용되는 자료 구조이다. 
	Hash table은 Hash 함수를 사용하여 색인(index, Key)을 버킷(bucket)이나 슬롯(slot)의 배열로 계산한다.
*/

#include <stdio.h>
#include <string.h>
#include <memory.h>

#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096

typedef struct {
	char key[MAX_KEY + 1];
	char data[MAX_DATA + 1];
}Hash;
Hash tb[MAX_TABLE];

unsigned long hash(const char *str) {
	unsigned long hash = 5381;
	int c;

	while (c = *str++) {
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

int add(const char *key, char *data) {
	unsigned long h = hash(key);

	while (tb[h].key[0] != 0) {
		if (strcmp(tb[h].key, key) == 0)
			return 0;
		h = (h + 1) % MAX_TABLE;
	}
	strcpy(tb[h].key, key);
	strcpy(tb[h].data, data);
	return 1;
}

int find(const char *key, char *data) {
	unsigned long h = hash(key);
	int cnt = MAX_TABLE;

	while (tb[h].key[0] != 0 && cnt--) {
		if (strcmp(tb[h].key, key) == 0)
			return 1;
		h = (h + 1) % MAX_TABLE;
	}

	return 0;
}

int main()
{
	int T, N, Q;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(tb, 0, sizeof(tb));
		scanf("%d", &N);
		char k[MAX_KEY + 1];
		char d[MAX_DATA + 1];

		for (int i = 0; i < N; i++)
		{
			scanf("%s %s\n", &k, &d);
			add(k, d);
		}

		printf("#%d\n", test_case);

		scanf("%d", &Q);
		for (int i = 0; i < Q; i++)
		{
			char k[MAX_KEY + 1];
			char d[MAX_DATA + 1];

			scanf("%s\n", &k);

			if (find(k, d))
			{
				printf("%s\n", d);
			}
			else
			{
				printf("not find\n");
			}
		}
	}
	return 0;
}