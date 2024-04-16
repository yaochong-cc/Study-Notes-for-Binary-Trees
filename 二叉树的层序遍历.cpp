#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}//该构造函数接受一个整数参数x，并使用该值初始化val成员变量，然后将left和right指针设置为NULL。
};

// 层序遍历：
class Solution5 {
public:
    //层序遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root != NULL)que.emplace(root);
        while (!que.empty()) {
            vector<int> vec;
            int size = que.size();//记录当前队列中的节点数
            for (int i = 0; i < size; i++) {//遍历当前队列中的节点
                TreeNode* node = que.front();//获取队列的第一个元素
                vec.emplace_back(node->val);
                que.pop();
                if (node->left) que.emplace(node->left);
                if (node->right) que.emplace(node->right);
            }
            res.emplace_back(vec);
        }
        return res;
    }


    // 递归实现层序遍历
    class Solution {
    public:
        void order(TreeNode* cur, vector<vector<int>>& result, int depth)
        {
            if (cur == nullptr) return;
            if (result.size() == depth) result.push_back(vector<int>());
            result[depth].push_back(cur->val);
            order(cur->left, result, depth + 1);
            order(cur->right, result, depth + 1);
        }
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> result;
            int depth = 0;
            order(root, result, depth);
            return result;
        }
    };
};

int main() {
    Solution5 s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int>> res = s.levelOrder(root);
    for (auto vec : res) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}