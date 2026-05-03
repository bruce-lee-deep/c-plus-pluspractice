#include<iostream>
#include<vector>
#include"binary_search.h"
#include"sequential_search.h"
using namespace std;
int main() {
	vector<int>a = { 1,2,3,4,5,6,7,8,9 };
	int key = 5;
	int res=binSearch(a, key);
	cout << res;
}