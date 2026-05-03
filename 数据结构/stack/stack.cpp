#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;
//有效的括号
class Solution1_1{
public:
	bool isValid(string s) {
		size_t n = s.size();
		if (n % 2 != 0||n==0) {
			return false;
		}
		stack<int>stk;
		vector<char>num;
		for (char c : s) {
			if (c == '(') {
				num.push_back(-1);
			}
			else if (c == ')') {
				num.push_back(1);
			}
			else if (c == '[') {
				num.push_back(-2);
			}
			else if (c == ']') {
				num.push_back(2);
			}
			else if (c == '{') {
				num.push_back(-3);
			}
			else if (c == '}') {
				num.push_back(3);
			}
		}
		for (int i = 0; i < n; i++) {
			if (stk.empty()) {
				if (num[i] > 0) {
					return false;
				}
				else {
					stk.push(num[i]);
				}
				
			}
			else {
				int top = stk.top();
				if (top + num[i] == 0) {
					stk.pop();
				}
				else if(num[i]>0){
					return false;
				}
				else {
					stk.push(num[i]);
				}
			}
		}
		if (stk.empty()) {
			return true;
		}
		return false;
	}
};
class Solution1_2 {
public:
	bool isValid(string s) {
		unordered_map<char, int>m{
			{'(',1},{')',4},
			{'[',2},{']',5},
			{'{',3},{'}',6}
		};
		stack<char>st;
		bool istrue = true;
		for (char c : s) {
			int flag = m[c];
			if (flag >= 1 && flag <= 3) st.push(c);
			else if (!st.empty() && m[st.top()] == flag - 3) st.pop();
			else { istrue = false; break; }
		}
		if (!st.empty()) istrue = false;
		return istrue;
	}
};

//最小栈
class MinStack {
public:
	stack<int>A, B;
	MinStack() {}
	void push(int x) {
		A.push(x);
		if (B.empty() || x <= B.top()) {
			B.push(x);
		}
	}
	void pop() {
		if (A.top() == B.top()) {
			B.pop();
		}
		A.pop();	
	}
	int top() {
		return A.top();
	}
	int getMin() {
		return B.top();
	}
};
int main() {
	return 0;
}

//迷宫问题
