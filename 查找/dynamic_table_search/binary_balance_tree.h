#pragma once
//每个节点的左右子树高度差最多为1；搜索、插入、删除操作都能在对数时间内完成
//左旋时，冲突的左孩变右孩，右旋时，冲突的右孩变左孩
//每插入一个节点要判断是否失衡，失衡进行调整
//1.LL：2,1，2右旋
//2.RR：-2，-1，-2左旋
//3.LR：2，-1，先对1左旋，再对2右旋
//4.RL：-2，1，先对-1右旋，再对-2左旋

//节点设计
template<class K,class V>
struct AVLNode {
	K key;
	V val;
	int height;//以当前节点为根的子树高度
	AVLNode* left, * right;
	AVLNOde(const K&k,const V&v):key(k),val(v),height(1),left(nullptr),right(nullptr){}
};
//工具函数，高度，平衡因子，更新高度
template<class K,class V>
class AVLTree {
private:
	AVLNode<K, V>* root = nullptr;//利用类模版构造对象的特殊点<K,V>
	//获取节点高度
	int height(AVLNode<K, V>* x)return x ? x->height : 0;
	//获取平衡因子
	int balanceFactor(AVLNode<K, V>* x) {
		return height(x->left) - height(x->right);
	}
	//更新节点高度
	void updateHeight(AVLNode<K, V>* x) {
		x->height = max(height(x->left), height(x->right)) + 1;
	}
	//右旋:LL
	static AVLNode* <K, V>rotateRight(AVLNode<K, V>* y) {
		AVLNode<K, V>* x = y->left;
		y->left = x->right;
		x->right = y;
		updataHeight(y);
		updataHeight(x);
		return x;
	}
	//左旋：RR
	static AVLNode* <K, V>rotateLeft(AVLNode<K, V>* x) {
		AVLNode<K, V>* y = x->right;
		x->right = y->left;
		y->left = x;
		updataHeight(x);
		updataHeight(y);
		return y;
	}
	//插入节点并保持平衡
	AVLNode<K, V>* insert(AVLNode<K, V>* node, const K& key, const V& val) {
		if (!node) return new AVLNode<K, V>(key, val);
		if (key < node->key) {
			node->left = insert(node->left, key, val);
		} else if (key > node->key) {
			node->right = insert(node->right, key, val);
		} else {
			node->val = val; // 更新值
			return node;
		}
		updateHeight(node);
		int bf = balanceFactor(node);
		// LL
		if (bf > 1 && key < node->left->key) {
			return rotateRight(node);
		}
		// RR
		if (bf < -1 && key > node->right->key) {
			return rotateLeft(node);
		}
		// LR
		if (bf > 1 && key > node->left->key) {
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}
		// RL
		if (bf < -1 && key < node->right->key) {
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}
		return node;
	}
};