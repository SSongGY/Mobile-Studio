#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <list>
#include <queue>
using namespace std;
char check[100] = { 0 };

void bfs(list<int> s[], int start) {
	queue<int> q;
	q.push(start);
	check[start] = 1;

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		list<int>::iterator itor = s[num].begin();
		for (int i = 0; i < s[num].size(); i++) {
			if (check[*itor] != 1) {
				q.push(*itor);
				check[*itor] = 1;
			}
			itor++;
		}
	}
}

int main() {
	list<int> node[100];
	int N, M, U, V, count=0;

	scanf("%d %d", &N, &M);
	if (N < 2 || N > 100 || M < 1 || M >5500) return 0;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &U, &V);
		node[U].push_back(V);
		node[V].push_back(U);
	}

	bfs(node, 0);

	for (int i = 0; i < 100; i++)
		if (check[i] == 1) count++;

	if (count == N)
		printf("1");
	else
		printf("0");

	return 0;
}