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


//遍历
//递归法：
class Solution1 {
public://前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        res.push_back(root->val);//先将root的值压入res   //中
        res.insert(res.end(), preorderTraversal(root->left).begin(), preorderTraversal(root->left).end());//在res的末尾插入root->left的前序遍历结果(preorderTraversal(root->left))//左子树
        res.insert(res.end(), preorderTraversal(root->right).begin(), preorderTraversal(root->right).end());//在res的末尾插入root->right的前序遍历结果(preorderTraversal(root->right))//右子树
        return res;
    } 
};

//递归法2
class Solution2 {
public:
    // 前序遍历
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;//表示如果当前节点指针 cur 为 NULL（即表示当前树节点为空），则直接结束当前函数的执行，并返回到调用它的地方。
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
        return;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
  
};


//迭代法：
class Solution3 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)return res;
        stack<TreeNode*> sta;
        TreeNode* node = root;
        while (!sta.empty() || node != NULL) {
            while (node != NULL) {//中左
                res.emplace_back(node->val);//在res的末尾插入node->val
                sta.emplace(node);//将node压入栈中
                node = node->left;
            }
            node = sta.top();//栈顶
            sta.pop();//弹出栈顶
            node = node->right;
        }
        return res;
    }

   
};
//统一风格的迭代法：
class Solution4 {
public:
    //使用NULL进行标记；
    // 前序遍历：
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左
                st.push(node);                          // 中
                st.push(NULL);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
   
};

int main() {
    Solution4 s;
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