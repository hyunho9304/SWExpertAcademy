/*
	다익스트라 알고리즘은 어떤 변도 음수 가중치를 갖지 않는 유향 그래프에서
	주어진 출발점과 도착점 사이의 최단 경로 문제를 푸는 알고리즘이다
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <string>
#include <numeric>
#include <sstream>

#define N 100
#define INF 100000

int map[N + 1][N + 1];
int visit[N + 1];
int dist[N + 1];
int vertex;
int edge;
int start;
int end;

void dijkstra(void) {
	int i, j, min, v;
	dist[start] = 0;
	for (i = 1; i <= vertex; i++) {
		min = INF;
		
		//방문 안한 최소 비용 지점 검색
		for (j = 1; j <= vertex; j++) {
			if (visit[j] == 0 && min > dist[j]) {
				min = dist[j];
				v = j;
			}
		}
		
		//방문
		visit[v] = 1;
		
		//방문한 지점에서 각 지점과의 비용 계산
		for (j = 1; j <= vertex; j++) {
			if (dist[j] > dist[v] + map[v][j])
				dist[j] = dist[v] + map[v][j];
		}
	}
}

int main()
{
	int test_case, i, j, T, from, to, value;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d %d", &vertex, &start, &end);
		scanf("%d", &edge);

		for (i = 1; i <= vertex; i++) {
			for (j = 1; j <= vertex; j++) {
				if (i != j)
					map[i][j] = INF;
			}
		}

		for (i = 1; i <= edge; i++){
			scanf("%d %d %d", &from, &to, &value);
			map[from][to] = value;
		}

		for (i = 1; i <= vertex; i++) {
			dist[i] = INF;
			visit[i] = 0;
		}
		printf("#%d ", test_case);
		dijkstra();
		printf("%d\n", dist[end]);
	}

	return 0;
}