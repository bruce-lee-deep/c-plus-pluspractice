#pragma once
#include<iostream>
#include<vector>
using namespace std;
// 深度优先搜索
void DFSUtil(int v, vector<bool>& visited, const vector<vector<int>>& adj) {
	visited[v] = true;
	cout << v << " ";
	for (int i : adj[v]) {
		if (i!=0&&!visited[i]) {//邻接且未访问
			DFSUtil(i, visited, adj);
		}
	}
}