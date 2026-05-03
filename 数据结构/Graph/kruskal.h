#pragma once
// 克鲁斯卡尔算法：基于并查集（Disjoint Set Union）构建最小生成树（MST）
// 输入：顶点数 V，边列表 edges（每条边 (u,v,weight)）
// 注意：若需要从邻接矩阵调用，可先把矩阵转换为边列表再调用本函数。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int u;
	int v;
	int w;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

class DSU {
public:
	explicit DSU(int n) : parent(n), rank_(n, 0) {
		for (int i = 0; i < n; ++i) parent[i] = i;
	}
	int find(int x) {
		if (parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}
	bool unite(int a, int b) {
		int pa = find(a), pb = find(b);
		if (pa == pb) return false;
		if (rank_[pa] < rank_[pb]) parent[pa] = pb;
		else if (rank_[pb] < rank_[pa]) parent[pb] = pa;
		else {
			parent[pb] = pa;
			rank_[pa]++;
		}
		return true;
	}
private:
	vector<int> parent;
	vector<int> rank_;
};

// 运行 Kruskal 并打印 MST 边与总权重。顶点编号应在 [0, V-1]。
inline void kruskalMST(int V, const vector<Edge>& edges) {
	if (V <= 0) return;
	// 复制并按权重排序
	vector<Edge> sorted = edges;
	sort(sorted.begin(), sorted.end(), [](const Edge& a, const Edge& b) {
		return a.w < b.w;
		});

	DSU dsu(V);
	vector<Edge> mst;
	mst.reserve(V > 0 ? V - 1 : 0);

	for (const auto& e : sorted) {
		if (e.u < 0 || e.u >= V || e.v < 0 || e.v >= V) {
			cerr << "kruskalMST: 边端点超出范围: " << e.u << " - " << e.v << '\n';
			continue;
		}
		if (dsu.unite(e.u, e.v)) {
			mst.push_back(e);
			if (static_cast<int>(mst.size()) == V - 1) break;
		}
	}

	// 输出结果
	int totalWeight = 0;
	cout << "Edge\tWeight\n";
	for (const auto& e : mst) {
		cout << e.u << " - " << e.v << "\t" << e.w << '\n';
		totalWeight += e.w;
	}
	if (static_cast<int>(mst.size()) != V - 1) {
		cout << "Warning: 图不连通，无法构成完整的 MST。已构建的生成森林包含 " << mst.size() << " 条边。\n";
	}
	cout << "Total weight: " << totalWeight << '\n';
}