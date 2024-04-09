#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

////从中序与后序遍历构造二叉树
////class Solution {
////private:
////    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
////        if (postorder.size() == 0) return NULL;
////
////        int rootValue = postorder[postorder.size() - 1];
////        TreeNode* root = new TreeNode(rootValue);// root树的根节点
////
////        if (postorder.size() == 1) return root;
////
////        int index;
////        for (index = 0; index < postorder.size(); index++) {
////            if (inorder[index] == rootValue) break;
////        }
////        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);//左闭右开
////        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());//inorder.end()指向 vector inorder 中最后一个元素的后一个位置。
////
////        postorder.resize(postorder.size() - 1);//删除最后一个元素，即root的根节点
////        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
////        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
////
////        root->left = traversal(leftInorder, leftPostorder);
////        root->right = traversal(rightInorder, rightPostorder);
////
////        return root;
////    }
////public:
////    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
////        if (postorder.size() == 0||inorder.size()==0) return NULL;
////        return traversal(inorder, postorder);
////    }
////};
//
//
////改进
////class Solution {//从中序与后序遍历构造二叉树
////private:
////    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
////        if (postorder.size() == 0) return NULL;
////
////        int rootValue = postorder[postorder.size() - 1];
////        TreeNode* root = new TreeNode(rootValue);// root树的根节点
////
////        if (postorder.size() == 1) return root;
////
////        int index;
////        for (index = 0; index < postorder.size(); index++) {
////            if (inorder[index] == rootValue) break;
////        }
////        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);//左闭右开
////        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());//inorder.end()指向 vector inorder 中最后一个元素的后一个位置。
////
////        postorder.resize(postorder.size() - 1);//删除最后一个元素，即root的根节点
////        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
////        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
////
////
////
////        // 以下为日志
////        cout << "----------" << endl;
////
////        cout << "leftInorder :";
////        for (int i : leftInorder) {
////            cout << i << " ";
////        }
////        cout << endl;
////
////        cout << "rightInorder :";
////        for (int i : rightInorder) {
////            cout << i << " ";
////        }
////        cout << endl;
////
////        cout << "leftPostorder :";
////        for (int i : leftPostorder) {
////            cout << i << " ";
////        }
////        cout << endl;
////        cout << "rightPostorder :";
////        for (int i : rightPostorder) {
////            cout << i << " ";
////        }
////        cout << endl;
////
////
////        root->left = traversal(leftInorder, leftPostorder);
////        root->right = traversal(rightInorder, rightPostorder);
////
////        return root;
////    }
////public:
////    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
////        if (postorder.size() == 0|| inorder.size()==0) return NULL;
////        return traversal(inorder, postorder);
////    }
////};
//
//////使用索引，减少vector
////class Solution {//从中序与后序遍历构造二叉树
////private:
////    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
////        if (postStart == postEnd) return NULL;
////
////        int rootValue = postorder[postEnd - 1];
////        TreeNode* root = new TreeNode(rootValue);
////
////        if (postEnd - postStart == 1) return root;
////
////        int index;
////        for (index = inStart; index < inEnd; index++) {
////            if (inorder[index] == rootValue) break;
////        }
////
////        //切割中序
////        //左中序[inStart,index)
////        int leftInBegin = inStart;
////        int leftInEn= index;
////        //右中序[index+1,inEnd)
////        int rightInBegin = index + 1;
////        int rightInEn = inEnd;
////        //切割后序
////        //左后序[postStart,postStart +index - inStart)
////        int leftPostBegin = postStart;
////        int leftPostEn = postStart +index - inStart;
////        //右后序[postStart + index - inStart,postEnd - 1)
////        int rightPostBegin = postStart + index - inStart ;//区间都是左闭右开
////        int rightPostEn = postEnd - 1;
////
////        root->left = traversal(inorder, postorder, leftInBegin, leftInEn, leftPostBegin, leftPostEn);
////        root->right = traversal(inorder, postorder, rightInBegin, rightInEn, rightPostBegin, rightPostEn);
////
////        return root;
////    }
////public:
////    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
////        if (postorder.size() == 0 || inorder.size() == 0) return NULL;
////        return traversal(inorder, postorder,0,inorder.size(),0,postorder.size());
////    }
////};
//int main() {        
//    Solution sol;
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4); 
//    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(7);
//
//    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
//    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
//
//    TreeNode* newRoot = sol.buildTree(inorder, postorder);
//
//    
//
//
//    return 0;
//}





//--------------------------------------------------------------------------
//同理，用前序遍历和中序遍历构造二叉树
//class Solution {
//private:
//    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE) {
//        if (preE == preS) return NULL;//preE指向数组最后一位的下一位！！！
//
//        int rootValue = preorder[preS];
//        TreeNode* root = new TreeNode(rootValue);
//
//        if (preE - preS == 1) return root;//1(preE(数组最后一位的下一位）-0(preS)==1只有一个节点
//
//        
//       
//        //寻找截断点
//        int index = 0;
//        for (index = inS; index < inE; index++) {
//            if (inorder[index] == rootValue) break;
//        }
//        //切割中序
//        
//        int leftInBegin = inS;
//        int leftInEn = index;
//
//        int rightInBegin = index + 1;
//        int rightInEn = inE;
//        //切割前序
//       
//        int leftPreBegin = preS + 1;
//        int leftPreEn = preS + 1 + (index - inS);
//
//        int rightPreBegin = preS + 1 + (index - inS);//区间都是左闭右开
//        int rightPreEn = preE;
//
//
//        root->left = traversal(preorder, inorder, leftPreBegin, leftPreEn, leftInBegin, leftInEn);
//        root->right = traversal(preorder, inorder, rightPreBegin, rightPreEn, rightInBegin, rightInEn);
//
//        return root;
//    }
//public:
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        if (preorder.size() == 0 || inorder.size() == 0) return NULL;
//        return traversal(preorder, inorder, 0, preorder.size(), 0, inorder.size());
//    }
//};

////另一种写法
//class Solution {
//private:
//    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
//        if (preStart >= preEnd) return NULL;
//
//        int rootValue = preorder[preStart];
//        TreeNode* root = new TreeNode(rootValue);
//
//        if (preEnd - preStart == 1) return root;
//
//        int index = 0;
//        for (index = inStart; index < inEnd; index++) {
//            if (inorder[index] == rootValue) break;
//        }
//
//        int leftTreeSize = index - inStart;
//        int rightTreeSize = inEnd - index - 1;
//
//        root->left = traversal(preorder, inorder, preStart + 1, preStart + 1 + leftTreeSize, inStart, index);
//        root->right = traversal(preorder, inorder, preEnd - rightTreeSize, preEnd, index + 1, inEnd);
//        return root;
//    }
//
//public:
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        if (preorder.size() == 0 || inorder.size() == 0) return NULL;
//        return traversal(preorder, inorder, 0, preorder.size(), 0, inorder.size());
//    }
//};

//使用vector 的方法
class Solution {
private:
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;

        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);// root树的根节点

        if (preorder.size() == 1) return root;

        int index;

        for (index = 0; index < inorder.size(); index++) {
            if (inorder[index] == rootValue) break;
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);//左闭右开
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());//inorder.end()指向 vector inorder 中最后一个元素的后一个位置。

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());

        root->left = traversal(leftPreorder, leftInorder);
        root->right = traversal(rightPreorder, rightInorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return NULL;
        return traversal(preorder, inorder);
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);         
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
       

    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};

    TreeNode* newRoot = sol.buildTree(preorder, inorder);

    return 0;
}