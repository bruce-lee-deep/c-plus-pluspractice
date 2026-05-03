#pragma once
#include<iostream>
#include<vector>
using namespace std;
struct Student {
	string name;
	int score;
};
//顺序查找所给学生名字的分数
int seqSearch(const vector<Student>& students,int n, const string& target_name) {
	for (int i = 0; i < n; i++) {
		if (students[i].name == target_name) {
			return students[i].score;
		}
	}
	return - 1;
}