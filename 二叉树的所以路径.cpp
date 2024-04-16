//#include<iostream>
//#include<queue>
//#include<vector>
//#include<string>
//#include<stack>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
////class Solution {
////private:
////    void traversal(TreeNode* cur, vector<int>& path, vector<string>& res) {
////        path.push_back(cur->val);
////        if (cur->left == NULL && cur->right == NULL) {
////            string sPath;
////            for (int i = 0; i < path.size() - 1; i++) {
////                sPath += to_string(path[i]);
////                sPath += "->";
////            }
////            sPath += to_string(path[path.size() - 1]);//每次循环最后都会接上"->",最后一个字符后面没有"->"，所以要单独写在循环外面；
////            res.push_back(sPath);
////            return;
////        }
////        if(cur->left){
////            traversal(cur->left, path, res);
////            path.pop_back();
////        }
////        if(cur->right){
////            traversal(cur->right, path, res);
////            path.pop_back();
////        }
////    }
////public:
////    vector<string>binaryTreePaths(TreeNode* root) {
////        vector<string> res;
////        vector<int> path;
////        if (root == NULL) return res;
////        traversal(root, path, res);
////        return res;
////    }
////};
////精简版：
////class Solution {
////private:
////    void traversal(TreeNode* cur,string path,vector<string>&res){
////        path+=to_string(cur->val);
////        if(cur->left==NULL&&cur->right==NULL){
////            res.push_back(path);
////            return;
////        }
////        if(cur->left){
////            traversal(cur->left,path+"->",res);//回溯隐藏于此；
////        }
////        if(cur->right){
////            traversal(cur->right,path+"->",res);
////        }
////    }
////public:
////    vector<string> binaryTreePaths(TreeNode* root){
////        string path;
////        vector<string >res;
////        if(root==NULL)return res;
////        traversal(root,path,res);
////        return res;
////    }
////};
//
//
////迭代法：
////使用栈：
//class Solution {
//public:
//    vector<string>binaryTreePaths(TreeNode* root) {
//        vector<string>res;
//        stack<TreeNode*> treeSt;//树的节点
//        stack<string> pathSt;//路径的节点
//        if (root == NULL) return res;
//
//        treeSt.push(root);
//        pathSt.push(to_string(root->val));
//        while (!treeSt.empty()) {
//            TreeNode* node = treeSt.top(); treeSt.pop();
//            string path = pathSt.top(); pathSt.pop();
//            if (node->left == NULL && node->right == NULL) {
//                res.push_back(path);
//            }
//            if (node->right) {
//                treeSt.push(node->right);
//                pathSt.push(path + "->" + to_string(node->right->val));
//            }
//            if (node->left) {
//                treeSt.push(node->left);
//                pathSt.push(path + "->" + to_string(node->left->val));
//            }
//        }
//        return res;
//    }
//};
////使用队列
////class Solution{
////public:
////    vector<string>binaryTreePaths(TreeNode*root){
////        vector<string> res;
////        queue<TreeNode*> treeQ;
////        queue<string> pathQ;
////        if(root==NULL) return res;
////
////        treeQ.push(root);
////        pathQ.push(to_string(root->val));
////        while(!treeQ.empty()){
////            TreeNode*node=treeQ.front();treeQ.pop();
////            string path=pathQ.front();pathQ.pop();
////
////            if(node->left==NULL&&node->right==NULL){
////                res.push_back(path);
////            }
////            if(node->left){
////                treeQ.push(node->left);
////                pathQ.push(path+"->"+ to_string(node->left->val));
////            }
////            if(node->right){
////                treeQ.push(node->right);
////                pathQ.push(path+"->"+ to_string(node->right->val));
////            }
////        }
////        return res;
////    }
////};
//int main() {
//    Solution sol = Solution();
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    vector<string> res = sol.binaryTreePaths(root);
//    for (int i = 0; i < res.size(); i++) {
//        cout << res[i] << endl;
//    }
//
//    return 0;
//}