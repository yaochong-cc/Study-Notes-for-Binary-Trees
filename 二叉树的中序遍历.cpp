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


////遍历
////递归法：
//class Solution1 {
//public:
//    //中序遍历
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> res;
//        if (root == NULL) return res;
//        res.insert(res.end(), inorderTraversal(root->left).begin(), inorderTraversal(root->left).end());
//        res.push_back(root->val);
//        res.insert(res.end(), inorderTraversal(root->right).begin(), inorderTraversal(root->right).end());
//        return res;
//    }
//};
//
////递归法2
//class Solution2 {
//public:
//    
//    //中序遍历
//    void traversal(TreeNode* cur, vector<int>& vec) {
//        if (cur == NULL) return;
//        traversal(cur->left, vec);  // 左
//        vec.push_back(cur->val);    // 中
//        traversal(cur->right, vec); // 右
//    }
//
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> result;
//        traversal(root, result);
//        return result;
//    }
//  
//};


//迭代法：
class Solution3 {
public:
   
    //中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)return res;
        stack<TreeNode*> sta;
        TreeNode* node = root;
        while (!sta.empty() || node != NULL) {
            while (node != NULL) {
                sta.emplace(node);//将node压入栈中
                node = node->left;//左
            }
            node = sta.top();//栈顶
            res.emplace_back(node->val);//在res的末尾插入node->val//中
            sta.pop();//弹出栈顶
            node = node->right;//右
        }
        return res;
    }

};
////统一风格的迭代法：
//class Solution4 {
//public:
//    //使用NULL进行标记；
//  
//    //中序遍历:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> res;
//        stack<TreeNode*> sta;
//        if (root != NULL) sta.push(root);
//        while (!sta.empty()) {
//            TreeNode* node = sta.top();
//            if (node != NULL) {
//                sta.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
//                if (node->right) sta.push(node->right);  // 添加右节点（空节点不入栈）
//
//                sta.push(node);                          // 添加中节点
//                sta.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。
//
//                if (node->left) sta.push(node->left);    // 添加左节点（空节点不入栈）
//            }
//            else { // 只有遇到空节点的时候，才将下一个节点放进结果集
//                sta.pop();           // 将空节点弹出
//                node = sta.top();    // 重新取出栈中元素
//                sta.pop();
//                res.push_back(node->val); // 加入到结果集
//            }
//        }
//        return res;
//    }
//  
//};
int main() {
    Solution3 s;
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