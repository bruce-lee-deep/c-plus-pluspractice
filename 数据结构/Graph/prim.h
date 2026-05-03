#pragma once
#pragma once
// 普里姆算法：加点，适合稠密图，求最小生成树（基于邻接矩阵实现）
// 假定：graph 为 VxV 方阵，graph[i][j] == 0 表示无边，正数表示边权
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// 从 key 中选取不在 MST 集合中且 key 值最小的顶点
static int minKey(const vector<int>& key, const vector<bool>& inMST) {
	int minVal = numeric_limits<int>::max();
	int minIndex = -1;
	for (int v = 0; v < static_cast<int>(key.size()); ++v) {
		if (!inMST[v] && key[v] < minVal) {
			minVal = key[v];
			minIndex = v;
		}
	}
	return minIndex;
}

// 计算并输出最小生成树；同时输出每条边和总权重
inline void primMST(const vector<vector<int>>& graph) {
	int V = static_cast<int>(graph.size());
	if (V == 0) return;

	for (const auto& row : graph) {
		if (static_cast<int>(row.size()) != V) {
			cerr << "primMST: 图必须为方阵（邻接矩阵）\n";
			return;
		}
	}

	const int INF = numeric_limits<int>::max();
	vector<int> parent(V, -1);       // parent[i] 保存 i 在 MST 中的父节点
	vector<int> key(V, INF);         // key[i] 为连接到当前 MST 的最小边权
	vector<bool> inMST(V, false);    // 标记顶点是否已在 MST 中

	// 从顶点 0 开始（可改为任意起点）
	key[0] = 0;
	parent[0] = -1;

	// 需要选入 V-1 条边（或做 V 次顶点选择）
	for (int count = 0; count < V - 1; ++count) {
		int u = minKey(key, inMST);
		if (u == -1) break;      // 剩余不可达顶点，提前退出
		inMST[u] = true;

		// 用 u 松弛其邻接顶点
		for (int v = 0; v < V; ++v) {
			int w = graph[u][v];
			// w != 0 表示存在边；排除已在 MST 中的顶点；松弛 key[v]
			if (w != 0 && !inMST[v] && w < key[v]) {
				parent[v] = u;
				key[v] = w;
			}
		}
	}

	// 输出 MST 边与总权重
	int totalWeight = 0;
	cout << "Edge\tWeight\n";
	for (int i = 1; i < V; ++i) {
		if (parent[i] != -1) {
			cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << '\n';
			totalWeight += graph[i][parent[i]];
		}
		else {
			cout << "Vertex " << i << " is disconnected\n";
		}
	}
	cout << "Total weight: " << totalWeight << '\n';
}
