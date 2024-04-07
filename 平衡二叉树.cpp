#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL) {};
};
//class Solution {//递归法
//public:
//	int getDepth(TreeNode* node) {
//		if (node == NULL) return 0;
//		int leftDepth = getDepth(node->left);
//		if (leftDepth == -1) return -1;
//		int rightDepth = getDepth(node->right);
//		if (rightDepth == -1) return -1;
//		return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
//	}
//	bool isBalance(TreeNode* root) {
//		return getDepth(root) == -1 ? false : true;
//	}
//
//};

class Solution {
private:
    int getDepth(TreeNode* cur) {
        stack<TreeNode*> st;
        if (cur != NULL) st.push(cur);
        int depth = 0; // 记录深度
        int result = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);                          // 中
                st.push(NULL);
                depth++;
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左

            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
    }

public:
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == NULL) return true;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            if (abs(getDepth(node->left) - getDepth(node->right)) > 1) {
                return false;
            }
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return true;
    }
};

int main() {
	Solution s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);           
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	cout << s.isBalanced(root) << endl;	
	return  0;
}


