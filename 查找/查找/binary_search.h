#pragma once
//针对有序表的查找，每次将范围减半,时间复杂度O(log n)
#include<iostream>
#include<vector>
using namespace std;
int binSearch(const vector<int>& a, int key) {
	//针对升序排列的有序表
	//{1,2,3,4,5,6,7,8,9}
	int low = 0;
	int high = a.size() - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (a[mid] == key) return mid;
		if (a[mid] < key) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

