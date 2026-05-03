/*#include<iostream>
using namespace std;
int weight(int m, int n) {
	int res = 1;
	while (n > 0) {
		res *= m;
		n--;	
	}
	return res;
}
int main() {
	int k, q;
	string k_number;
	string q_number;
	cin >> k >> k_number>> q;
	int value=0;
	int len = k_number.length();
	for (int i = len - 1; i >= 0; i--) {
		int temp = k_number[len-1-i] - '0';
		if (temp >= 0 && temp <= 9) {
			value += temp * weight(k, i);
		}
		else {
			value += (temp - 7) * weight(k, i);
		}
	}
	cout << value << endl;
	while(value!=0){
		int temp = value % q;
		if (temp >= 0 && temp <= 9) {
			q_number = char(temp + '0') + q_number;
		}
		else {
			q_number = char(temp + 7 + '0') + q_number;
		}
		value /= q;
	}
	cout << q_number << endl;
	return 0;
}*/

