#pragma once
//每个节点最多有两个子节点，左子节点的值小于父节点，右子节点的值大于父节点
//基本操作时间复杂度为O(log n)或O(h)，最坏情况下为O(n)
#include<iostream>
using namespace std;
struct Node {
	int key;
	Node* left, * right;
	Node(int k) :key(k), left(nullptr), right(nullptr) {}
};
//动态查找，找到就返回，找不到就在适当位置插入
Node* searchInsert(Node*& root, int key) {
	Node* parent = nullptr; // 初始化为nullptr
	Node* cur = root;
	while (cur && cur->key != key) {
		parent = cur;
		cur = (key < cur->key) ? cur->left : cur->right;
	}
	if (cur) return cur;
	Node* insertNode = new Node(key);
	if (!parent) {
		// 树为空，插入为根节点
		root = insertNode;
	} else if (key < parent->key) {
		parent->left = insertNode;
	} else {
		parent->right = insertNode;
	}
	return insertNode;
}


//删除指定节点
// 当删除节点有两个子节点时，要递归一次删除最小节点
//找最小节点
Node* minNode(Node* p) {
	while (p->left)p = p->left;
	return p;
}
//删除key，返回新子树根
Node* remove(Node* root, int key) {
	if (!root)return nullptr;//空树
	Node* cur = root;
	Node* parent = nullptr;
	bool isLeft = false;
	//找到需要删除的节点
	while (cur && cur->key != key) {
		parent = cur;
		cur = (key < cur->key) ? cur->left : cur->right;
	}
	if (!cur) return root;//没找到，直接返回原始的root
	//如果找到了
	if (parent->left == cur) isLeft= true;
	//1.如果为叶子节点，直接删除
	if (!cur->left && !cur->right) {
		if (cur == root) {//如果删除的是根节点
			delete cur;
			return nullptr;
		}
		else if(isLeft==true){
			parent->left = nullptr;
		}
		else if (isLeft == false) {
			parent->right = nullptr;
		}
		delete cur;
		return root;
	}
	//2.一个子树
	if (!(cur->left && cur->right)) {
		if (cur->left) {//左子树非空
			if (isLeft) {
				parent->left = cur->left;
			}
			else {
				parent->right = cur->left;
			}
		}
		else {
			if (isLeft) {
				parent->left = cur->right;
			}
			else {
				parent->right = cur->right;
			}
		}
		delete cur;
		return root;
	}
	//3.两个子树
	Node* successor = minNode(cur->right);//找到右子树的最小节点或左子树的最大节点
	cur->key = successor->key;
	cur->right = remove(cur->right,successor->key);//递归删除最后的那个节点，这个节点最多有一个子树
	return root;
}