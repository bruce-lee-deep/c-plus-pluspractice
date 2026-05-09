#include<iostream>
using namespace std;
int main() {
	int t, s, p;
	cin >> t >> s >> p;
	int ts = t + s;
	int tp = t + p;
	int sp = s + p;
	if (ts == 2 * p || tp == 2 * s || sp == 2 * t) {
		cout << "Yes" << endl;
	}
	else {
		cout << " No" << endl;
	}
	return 0;
}
