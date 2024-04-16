#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int pre = 0;//记录前一个节点的数值
    void traversal(TreeNode* cur) {
        if (cur == NULL) return;
        traversal(cur->right);//右
        cur->val += pre;//中
        pre = cur->val;
        traversal(cur->left);//左
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int pre = 0;
        traversal(root);
        return root;
    }
    //前序遍历
    void preorder(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    Solution sol;
    sol.convertBST(root);
    vector<int> res;
    sol.preorder(root, res);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}