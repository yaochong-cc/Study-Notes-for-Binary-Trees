//递归三部曲：
//1. 递归定义：确定递归函数的返回值和参数；
//2. 终止条件：当前节点为空。
//3. 递归步骤：先递归翻转左子树，再递归翻转右子树，最后交换左右子树的指针。

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;            // 节点值
    TreeNode* left;     // 左子节点
    TreeNode* right;    // 右子节点
    TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

// 翻转二叉树
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    //交换左右子树的指针
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    //递归翻转左右子树
    invertTree(root->left);
    invertTree(root->right);
    return root;
    }
void printTree(TreeNode* root) {//中序遍历
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

// 递归-层序遍历
void order(TreeNode* cur, int depth) {
    if (cur == NULL) return;
    swap(cur->left, cur->right);
    order(cur->left, depth + 1);
    order(cur->right, depth + 1);
}
TreeNode* invertTree2(TreeNode* root) {
    int depth = 0;
    order(root, depth);
    return root;
}

// 迭代-栈（先序遍历）
TreeNode* invertTree3(TreeNode* root) {
    if (root == NULL) return root;
    stack<TreeNode*> st;
    st.emplace(root);
    while (!st.empty()) {
        TreeNode* cur = st.top();
        st.pop();
        swap(cur->left, cur->right);
        if (cur->right) st.emplace(cur->right);
        if (cur->left) st.emplace(cur->left);
    }
    return root;
}
// 迭代-队列（层序遍历）
TreeNode* invertTree4(TreeNode* root) {
    if (root == NULL)  return root;
    queue <TreeNode*> que;
    que.emplace(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* cur = que.front();
            que.pop();
            swap(cur->left, cur->right);
            if (cur->left) que.emplace(cur->left);
            if (cur->right) que.emplace(cur->right);
        }
    }
    return root;
}


int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);          
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);


    // 输出原二叉树
    cout << "原二叉树：" << endl;    
    printTree(root);

    // 翻转二叉树
    root = invertTree(root);
    // root = invertTree2(root);
    // root = invertTree3(root);
    // root = invertTree4(root);    

    // 输出翻转后的二叉树
    cout << "翻转后的二叉树：" << endl;
    printTree(root);    
  
    return 0;
}   