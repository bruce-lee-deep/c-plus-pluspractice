#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	long long res=LLONG_MAX;
	cin >> n >> m;
	vector<int>value(n);
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}
	vector<vector<int>>graph(n,vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a-1][b-1] = 1;
		graph[b - 1][a - 1] = 1;
	}

	for(int i = 0; i < n; i++ ){
		long long temp = 0;
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1) {
				temp += value[j];
			}
		}
		res = min(res, temp);
    }
	cout << res << endl;
	return 0;
}