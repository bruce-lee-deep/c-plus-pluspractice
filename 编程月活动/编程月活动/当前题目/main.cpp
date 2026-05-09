#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
//定义高度
vector<vector<int>>h;
vector<vector<int>>dp;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int x, int y) {
	if (dp[x][y]!=0) return dp[x][y];//如果dp[x][y]不为0，说明已经被计算过，直接返回

	dp[x][y] = 1;
	//去遍历四个方向，看看能不能走
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && h[nx][ny] <= h[x][y]) {
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
		}
	}
	return dp[x][y];
}

int main() {
	cin >> n >> m;
	h.assign(n, vector<int>(m));
	dp.assign(n, vector<int>(m, 0));
	//输入高度
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> h[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans << endl;
	return 0;
}