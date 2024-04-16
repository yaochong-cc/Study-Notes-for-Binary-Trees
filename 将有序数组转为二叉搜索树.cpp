//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;    
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//private:
//    TreeNode* traversal(vector<int>& num,int left,int right){
//        //返回条件
//        if (left > right) return NULL;
//        //递归逻辑
//        int mid = left + (right - left) / 2;//防止数值越界
//        TreeNode* root = new TreeNode(num[mid]);
//        root->left = traversal(num, left, mid - 1);
//        root->right = traversal(num, mid + 1, right);
//        return root;
//    }
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        TreeNode* root = traversal(nums, 0, nums.size() - 1);
//        return root;
//        
//    }
//    //前序遍历
//    void preorderTraversal(TreeNode* root,vector<int>& res) {
//        if(root == NULL) return;
//        res.push_back(root->val);
//        preorderTraversal(root->left,res);
//        preorderTraversal(root->right,res);
//    }
//    
//};
//
//int main() {
//    Solution s;
//    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
//    TreeNode* root = s.sortedArrayToBST(nums);
//    vector<int> res;
//    s.preorderTraversal(root,res);
//    for(int i=0;i<res.size();i++) {
//        cout<<res[i]<<" ";
//    }   
//    return 0;
//}   