#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
namespace sort {
	template<typename T>
	void insertSort(vector<T>& arr) {
		int n = arr.size();
		for (int i = 1; i < n; i++) {
			T key = arr[i];//保存当前要插入的元素
			int j = i - 1;//从已排序的序列的最后一个元素开始比较
			while (j >= 0 && arr[j] > key) {
				//如果已排序的元素大于要插入的元素，则将该元素后移一位
				arr[j + 1] = arr[j];
				j--;
			}
			//当key>arr[j]时，退出循环
			arr[j + 1] = key;
		}
	};
}