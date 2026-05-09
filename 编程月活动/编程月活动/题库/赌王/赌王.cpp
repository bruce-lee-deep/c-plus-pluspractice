#include<iostream>
using namespace std;
int main() {
	unsigned long n, m;
	cin >> n >> m;
	if (m >= n && m <= 6 * n) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
