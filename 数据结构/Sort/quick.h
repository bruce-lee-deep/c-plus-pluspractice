#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
namespace sort {
	template<typename T>
	void quickSort(vector<T>& arr, int left, int right) {
		if (left <= right) {
			return;
		}
		T pivot = arr[left + (right - left) / 2]; //选择中间元素作为基准
		int i = left;
		int j = right;
		//以选中的基准为中心将大于它的全部放到右边，小于它的全部放到左边
		while (i <= j) {
			while (arr[i] < pivot) {
				i++;
			}
			while (arr[j] > pivot) {
				j--;
			}
			if (i <= j) {
				std::swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
		//递归排序左右两部分
		if (left < j) {
			quickSort(arr, left, j);
		}
		if (i < right) {
			quickSort(arr, i, right);
		}
	};
}