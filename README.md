# Study-Notes-for-Binary-Trees
​
这是一个小白学习二叉树的学习笔记。

## 定义二叉树的节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}//该构造函数接受一个整数参数x，并使用该值初始化val成员变量，然后将left和right指针设置为NULL。
};

## 二叉树的遍历方式
深度优先遍历        
前序遍历：中->左->右
中序遍历：左->中->右
后序遍历：左->右->中
广度优先遍历：层序遍历
深度优先遍历：
### 递归法：
 前序遍历：

将遍历得到的数存入一个vector容器中，先存入根节点的值，之后先遍历左子树，再遍历右子树。对子树也依据相同的遍历逻辑，形成递归。

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == NULL) return res;
    res.push_back(root->val);//先将root的值压入res   //中
    res.insert(res.end(), preorderTraversal(root->left).begin(), preorderTraversal(root->left).end());//在res的末尾插入root->left的前序遍历结果(preorderTraversal(root->left))//左子树
    res.insert(res.end(), preorderTraversal(root->right).begin(), preorderTraversal(root->right).end());//在res的末尾插入root->right的前序遍历结果(preorderTraversal(root->right))//右子树
    return res;
}

同理可以写出中序遍历和后序遍历的算法。

中序遍历：
、、、
 vector<int> inorderTraversal(TreeNode* root) {
     vector<int> res;
     if (root == NULL) return res;
     res.insert(res.end(), inorderTraversal(root->left).begin(), inorderTraversal(root->left).end());
     res.push_back(root->val);
     res.insert(res.end(), inorderTraversal(root->right).begin(), inorderTraversal(root->right).end());
     return res;
 }

后序遍历：

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == NULL) return res;
    res.insert(res.end(), postorderTraversal(root->left).begin(), postorderTraversal(root->left).end());
    res.insert(res.end(), postorderTraversal(root->right).begin(), postorderTraversal(root->right).end());
    res.push_back(root->val);
    return res;
}
、、、
当然也可以先定义一个函数进行递归，再调用之。

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

我们来leetCode上提交一下，结果非常Amzaing，执行用时仅仅打败了10%的用户。

 力扣144二叉树的前序遍历

力扣94二叉树的中序遍历

力扣145二叉树的后序遍历



可见递归法的时间复杂度之高。我们尝试用迭代法改进遍历算法吧。

### 迭代法：
递归的实现就是每一次调用都会将函数的参数值、局部变量、地址等压入调用的栈中，返回时从栈顶弹出上一次递归的各项参数。

那么我们也尝试用栈来模拟非递归的二叉树遍历方法。

创建一个vector<int> res来存储遍历结果，再创建一个stack<TreeNode*> sta来模拟遍历的过程，定义一个指针node来遍历所有节点。

先将根节点的值存入res中（中），再依次将最左边的节点压入sta中，直到叶节点（左）。让node指向栈顶，这样每弹出一个栈顶，指针就返回上一层，之后让node指向right,再用同样的逻辑遍历右子树（右）,至此完成了中->左->右的遍历。



emplace_back:
emplace_back 是 std::vector 容器的成员函数，它允许我们在 vector 的末尾直接构造一个新的元素。与 push_back 类似，但它使用了就地构造的方式，允许在 vector 的末尾构造元素，而不是通过复制或移动一个已有的对象来添加新的元素。比push_back 拥有更高的效率。
适用于 std::vector 容器
emplace:
emplace 是多种容器的成员函数，比如 std::vector、std::map、std::set 、std::unordered_map、std:unordered_set、std::multiset.stack也可以使用emplace();
它允许在容器内部执行原位构造，即在容器中直接构造新的元素，而不是通过复制或移动一个已有的对象来插入新的元素。
前序遍历：

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == NULL)return res;
    stack<TreeNode*> sta;
    TreeNode*  node = root;
    while (!sta.empty() || node != NULL) {
        while (node != NULL) {
            res.emplace_back(node->val);//中
            sta.emplace(node);//将node压入栈中
            node = node->left;//左
        }
        node = sta.top();//栈顶
        sta.pop();//弹出栈顶
        node = node->right;//右
        }
    return res;
   }

同理，我可以得出中序遍历

中序遍历：

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == NULL)return res;
    stack<TreeNode*> sta;
    TreeNode*  node = root;
    while (!sta.empty() || node != NULL) {
        while (node != NULL) {
            sta.emplace(node);
            node = node->left;//将左子树的节点依次压入栈中，直到叶节点（此时下一个左节点为空）
        }
        node = sta.top();//指针指向栈顶
        res.emplace_back(node->val);//在res中存入左子树的节点
        sta.pop();//弹出栈顶
        node = node->right;//指向下一个右节点，若下一个右节点为空，指针指向上一层，并在res中存入中节点的值。若下一个节点不为空，则在res中存入右节点的值。
        }
    return res;
}
后序遍历：

后序遍历又有不同。后序遍历是 左->右->中 的逻辑，所以在存入中节点之前要确保右节点已全部存入，所以我们引入一个新的指针，last_visited来判断右节点是否判断过。

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == NULL) return res;

    stack<TreeNode*> sta;
    TreeNode* node = root;
    TreeNode* last_visited = NULL; // 用于记录最后访问过的节点

    while (!sta.empty() || node != NULL) {
        while (node != NULL) {
            sta.push(node);// 将节点压入栈中
            node = node->left; // 先访问左节点
        }
        TreeNode* top_node = sta.top(); // 查看栈顶元素，但不弹出
        if (top_node->right == NULL || top_node->right == last_visited) {
            // 当右节点为空或者已经被访问过时，就可以访问根节点了
            res.push_back(top_node->val);
            sta.pop(); // 弹出已经访问过的节点
            last_visited = top_node;
        }
        else {
            // 访问右节点
            node = top_node->right;
        }
    }
    return res;
}

过啦！击败全世界的人！



也许，还有别的方法：

前序遍历：

中->左->右；

先存储根节点到res里，然后在栈中存储存储所有的右节点，再存储所有的左节点。最后将栈内的元素依次放入res中，这样就可以保证res 内的顺序是中->左->右了。

vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        vector<int> res;
        if (root == NULL) return res;
        sta.emplace(root);
        while (!sta.empty()) {
            TreeNode* node = sta.top();                    
            sta.pop();
            res.emplace_back(node->val);
            if (node->right) sta.emplace(node->right);          
            if (node->left) sta.emplace(node->left);            
        }
        return res;
    }
后序遍历：

中->左->右   ==>  中->右->左  ==>  左 ->右->中

依照此逻辑，我们只需要再前序遍历的基础上进行改进即可。

只需要改变入栈顺序，输出中->右->左 的res，并且反转res，得到 左 ->右->中 即可。

代码如下：统一

 vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        vector<int> res;
        if (root == NULL) return res;
        sta.emplace(root);
        while (!sta.empty()) {
            TreeNode* node = sta.top();
            sta.pop();
            res.emplace_back(node->val);
            if (node->left) sta.emplace(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right) sta.emplace(node->right); // 空节点不入栈
        }
        reverse(res.begin(), res.end()); // 将结果反转之后就是左右中的顺序了
        return res;
    }
### 统一的代码风格
对于中节点，我们用NULL进行标记，单独处理。这样只需要改变代码的顺序就可以描述三种不同的遍历方式。

此处的代码和思想借鉴自 代码随想录  代码随想录原文

//使用NULL进行标记
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

## 广度优先遍历（层序遍历）
迭代法
栈是先进后出，符合深度遍历的要求。而对于层序遍历，是从depth=0开始，每一层从左向右遍历。属于先进先出的情况，我们可以用对列（queue）进行模拟.

在层序遍历，我们需要在处理每一层节点时，仅处理当前队列中的节点。通过使用 size 变量，我们在每一轮循环中只处理当前队列中所含有的节点，这样可以确保我们按照层级来遍历树中的节点。

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if (root != NULL)que.emplace(root);
    while (!que.empty()) {
        vector<int> vec;
        int size = que.size();//记录当前队列（树的层）中的节点数
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

递归法
void order(TreeNode*cur,vector<vector<int>>& res ,int depth){
        if(cur==NULL) return ;
        if(res.size()==depth) res.emplace_back(vector<int>());
        res[depth].emplace_back(cur->val);
        order(cur->left,res,depth+1);
        order(cur->right,res,depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int depth=0;
        order(root,res,depth);
        return res;
    }

​
