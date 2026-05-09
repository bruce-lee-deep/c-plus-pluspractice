#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++) {
		unsigned long long a;
		cin >> a;
		sum += a;
		cout << sum;
		if (i != n - 1) cout << " ";
	}
	return 0;
}