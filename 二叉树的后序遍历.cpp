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
public:
   
    //后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        res.insert(res.end(), postorderTraversal(root->left).begin(), postorderTraversal(root->left).end());
        res.insert(res.end(), postorderTraversal(root->right).begin(), postorderTraversal(root->right).end());
        res.push_back(root->val);
        return res;
    }
};

//递归法2
class Solution2 {
public:
   
    //后序遍历
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
        vec.push_back(cur->val);    // 中
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};


//迭代法：
class Solution3 {
public:
    
    //后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;

        stack<TreeNode*> sta;
        TreeNode* node = root;
        TreeNode* last_visited = NULL; // 用于记录最后访问过的节点

        while (!sta.empty() || node != NULL) {
            while (node != NULL) {
                sta.push(node);// 将节点压入栈中
                node = node->left; // 先访问左孩子
            }

            TreeNode* top_node = sta.top(); // 查看栈顶元素，但不弹出
            if (top_node->right == NULL || top_node->right == last_visited) {
                // 当右孩子为空或者已经被访问过时，就可以访问根节点了
                res.push_back(top_node->val);
                sta.pop(); // 弹出已经访问过的节点
                last_visited = top_node;
            }
            else {
                // 访问右孩子
                node = top_node->right;
            }
        }
        return res;
    }
   
};
//统一风格的迭代法：
class Solution4 {
public:
    //使用NULL进行标记；
    
    //后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);                          // 中
                st.push(NULL);

                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左

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
    Solution1 s;
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