#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct edge { int to, length = 1; };

int dijksra_change(const vector<vector<edge>> &graph, int X, int Y) {
	vector<int> min(graph.size(), INT_MAX);
	min[X] = 0;
	set<pair<int, int>> module;
	module.insert(make_pair(0, X));
	while (!module.empty()) {
		int goal = module.begin()->second;
		if (goal == Y)
			return min[goal];
		module.erase(module.begin());
		for (auto ed : graph[goal]) {
			if (min[ed.to] > min[goal] + ed.length) {
				module.erase(make_pair(min[ed.to], ed.to));
				min[ed.to] = min[goal] + ed.length;
				module.insert(make_pair(min[ed.to], ed.to));
			}
		}
	}
	return 0;
}

int main() {
	struct edge conn;
	vector<edge> line;
	vector<vector<edge>> graph(100,line);
	int N, M, X, Y, U, V;

	scanf("%d %d", &N, &M);
	if (N < 2 || N>100 || M < 1 || M>5500) return 0;

	scanf("%d %d", &X, &Y);
	if (X<0 || X > N || Y<0 || Y>N) return 0;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &U, &V);
		if(graph[U].empty()){
			conn.to = V;
			line.push_back(conn);
			graph[U]=line;
			line.clear();
		}
		else {
			line = graph[U];
			conn.to = V;
			line.push_back(conn);
			graph[U] = line;
			line.clear();
		}
		if (graph[V].empty()) {
			conn.to = U;
			line.push_back(conn);
			graph[V] = line;
			line.clear();
		}
		else {
			line = graph[V];
			conn.to = U;
			line.push_back(conn);
			graph[V] = line;
			line.clear();
		}
	}

	printf("%d", dijksra_change(graph, X, Y));

	return 0;
}