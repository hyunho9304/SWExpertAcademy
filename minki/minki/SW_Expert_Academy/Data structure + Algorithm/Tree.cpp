/*
	트리 구조란 그래프의 일종으로, 여러 노드가 한 노드를 가리킬 수 없는 구조이다.
	간단하게는 회로가 없고, 서로 다른 두 노드를 잇는 길이 하나뿐인 그래프를 트리라고 부른다.
*/

#include <stdio.h>

#define MAX_NODE_NUM 10000
#define MAX_CHILD_NUM 2

typedef struct
{
	int parent;
	int child[MAX_CHILD_NUM];
} TreeNode;
TreeNode tree[MAX_NODE_NUM];
int nodeNum;
int edgeNum;
int root;

void initTree(void) {
	int i, j;
	for (int i = 0; i <= nodeNum; i++) {
		tree[i].parent = -1;
		for (j = 0; j < MAX_CHILD_NUM; j++) {
			tree[i].child[j] = -1;
		}
	}
}

void addChild(int parent, int child)
{
	int i;
	for (i = 0; i < MAX_CHILD_NUM; i++) {
		if (tree[parent].child[i] == -1)
			break;
	}
	tree[parent].child[i] = child;
	tree[child].parent = parent;
}

int getRoot(void) {
	int i, j;
	for (i = 1; i <= nodeNum; i++) {
		if (tree[i].parent == -1)
			return i;
	}

	return -1;
}

void preOrder(int root) {
	int i, child;
	printf("%d ", root);
	for (int i = 0; i < MAX_CHILD_NUM; i++) {
		child = tree[root].child[i];
		if (child != -1)
			preOrder(child);
	}
}

int main()
{
	int test_case;
	int T;
	int i;
	int parent;
	int child;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &nodeNum, &edgeNum);

		initTree();

		for (i = 0; i < edgeNum; i++)
		{
			scanf("%d %d", &parent, &child);
			addChild(parent, child);
		}

		root = getRoot();

		printf("#%d ", test_case);
		preOrder(root);
		printf("\n");
	}

	return 0;
}