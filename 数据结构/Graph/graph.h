#pragma once
#include<iostream>
#include<vector>
#include"dfs.h"
using namespace std;
class Graph {
public:
	int V; // 顶点数
	vector<vector<int>> adj;//邻接表
	vector<bool> visited; // 先声明为成员变量

	Graph(int V,vector<vector<int>>adj) {
		this->V = V;
		this->adj = adj;
		visited = vector<bool>(V, false); // 在构造函数中初始化
	}
	// 深度优先搜索
	void dfs() {
		DFSUtil(0, visited, adj);
	}
	//广度优先搜索

};
