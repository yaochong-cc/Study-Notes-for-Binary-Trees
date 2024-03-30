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

    //中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        res.insert(res.end(), inorderTraversal(root->left).begin(), inorderTraversal(root->left).end());
        res.push_back(root->val);
        res.insert(res.end(), inorderTraversal(root->right).begin(), inorderTraversal(root->right).end());
        return res;
    }

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
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;//表示如果当前节点指针 cur 为 NULL（即表示当前树节点为空），则直接结束当前函数的执行，并返回到调用它的地方。
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
        return;
    }
    
    // 前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    //中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    //后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
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
        TreeNode*  node = root;
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

    //中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)return res;
        stack<TreeNode*> sta;
        TreeNode*  node = root;
        while (!sta.empty() || node != NULL) {
            while (node != NULL) {
                sta.emplace(node);//将node压入栈中
                node = node->left;
            }
            node = sta.top();//栈顶
            res.emplace_back(node->val);//在res的末尾插入node->val
            sta.pop();//弹出栈顶
            node = node->right;
            }
        return res;
    }

   
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
    //中序遍历:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        if (root != NULL) sta.push(root);
        while (!sta.empty()) {
            TreeNode* node = sta.top();
            if (node != NULL) {
                sta.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) sta.push(node->right);  // 添加右节点（空节点不入栈）

                sta.push(node);                          // 添加中节点
                sta.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

                if (node->left) sta.push(node->left);    // 添加左节点（空节点不入栈）
            }
            else { // 只有遇到空节点的时候，才将下一个节点放进结果集
                sta.pop();           // 将空节点弹出
                node = sta.top();    // 重新取出栈中元素
                sta.pop();
                res.push_back(node->val); // 加入到结果集
            }
        }
        return res;
    }
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