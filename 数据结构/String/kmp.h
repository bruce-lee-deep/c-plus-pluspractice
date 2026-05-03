#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//构建前缀函数（next数组）
vector<int>buildNext(const string& pattern) {
	size_t m = pattern.size();
	vector<int>next(m, 0);
	int j = 0;//j表示当前相等最长前后缀长度，每一次计算next[i]时，就比较pattern[i]和pattern[j]就行，因为j就是前一个位置的最长前后缀长度，前面的是已经比较过的

	for (int i = 1; i < m; i++) {
		//当前后缀不匹配时，需要回退直到匹配
		while (j > 0 && pattern[i] != pattern[j]) {
			j = next[j - 1];
		}
		//当前后缀匹配，最长前后缀长度加1
		if (pattern[i] == pattern[j]) {
			j++;
		}
		next[i] = j;
	}
	return next;
}
//KMP字符串匹配算法
vector<int>kmpSearch(const string& text, const string& pattern) {
	vector<int>res;//记录所有匹配的其实位置
	int n = text.size();
	int m = pattern.size();
	if (m == 0 || n < m)return res;

	vector<int>next = buildNext(pattern);
	int j = 0;//模式串的指针
	for (int i = 0; i < n; i++) {
		//不匹配时，模式串指针回退
		while (j > 0 && text[i] != pattern[j]) {
			j = next[j - 1];
		}
		if (text[i] == pattern[j]) {
			j++;
		}
		//如果模式串完全匹配
		if (j == m) {
			res.push_back(i - m + 1);
			j = next[j - 1];
		}
	}
	return res;
}
