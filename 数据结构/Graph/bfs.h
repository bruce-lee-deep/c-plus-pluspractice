#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//广度优先搜索
void BFSUtil(int v, vector<bool>& visited, const vector<vector<int>>& adj) {
	queue<int>q;
	visited[v] = true;
	q.push(v);//入队
	while (!q.empty()) {
		int node = q.front();
		q.pop();//出队
		cout << node << " ";
		//遍历node的邻接点并入队
		for (int i : adj[node]) {
			if (i != 0 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
