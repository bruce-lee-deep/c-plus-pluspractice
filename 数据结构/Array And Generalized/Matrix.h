#pragma once
#include<iostream>
#include<vector>
using namespace std;
//重塑矩阵
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c)return mat;//如果参数不合理，直接返回原本的矩阵
		vector<vector<int>>res(r, vector<int>(c, 0));
        int row = 0, col = 0;
        for (int i = 0; i < m * n; i++) {
            if (col == c) {
                col = 0;
                row++;
            }
            res[row][col] = mat[i / n][i % n];
            col++;
        }
        return res;
    }
};
