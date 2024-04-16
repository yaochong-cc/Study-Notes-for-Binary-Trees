////假定 BST 有如下定义：
////
////结点左子树中所含结点的值小于等于当前结点的值
////结点右子树中所含结点的值大于等于当前结点的值
////左子树和右子树都是二叉搜索树
////
////
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;     
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//////对于普通的二叉树来说
////class Solution {
////private:
////    //map<int,int>   [key,value]分别指元素和出现频率
////    void searchBST(TreeNode* cur, unordered_map<int, int>& map) {
////        if (cur == NULL) return;
////        map[cur->val]++;//表示key（cur->val) 对应的value（频率）
////        searchBST(cur->left, map);
////        searchBST(cur->right, map);
////        return;
////    }
////    
////    bool static cmp(const pair<int, int>& a, const pair <int, int>& b) {
////        return a.second > b.second;//按照频率从大到小排序
////    }
////
////public:
////    vector<int>  findMode(TreeNode* root) {
////        unordered_map<int, int> map;
////        vector<int> res;
////        if (root == NULL) return res;
////        searchBST(root, map);
////        vector<pair<int, int>> vec(map.begin(), map.end());
////        sort(vec.begin(), vec.end(), cmp);//按频率排序
////        //ompare 是一个可调用的比较函数对象，用于确定元素的顺序。如果未提供该参数，std::sort 将使用默认的比较方式（operator<）进行排序。
////        
////        res.push_back(vec[0].first);
////        for (int i = 1; i < vec.size(); i++) {
////            if (vec[i].second == vec[0].second) res.push_back(vec[i].first);
////            else break;
////        }
////        return res;
////    }
////};  
//
////二叉搜索树 中序遍历有序
//class Solution {
//private:
//    int maxCount = 0;//最大频率
//    int count = 0;//统计频率
//    TreeNode* pre = NULL;
//    vector<int> result;
//    void searchBST(TreeNode* cur) {
//        if (cur == NULL) return;
//        //左
//        searchBST(cur->left);
//        //中
//        if (pre == NULL) {
//            count = 1;//第一个节点
//        }
//        else if (pre->val == cur->val) {
//            count++;
//        }
//        else {
//            count = 1;//与前一个值不同，计数更改为1；
//        }
//        pre = cur;//更新pre;
//
//        if (count == maxCount) {
//            result.push_back(cur->val);//频率和最大频率相同，放入result中
//        }
//
//        if (count > maxCount) {
//            maxCount = count;
//            result.clear();//一定不可省略
//            result.push_back(cur->val);
//        }
//        //右
//        searchBST(cur->right);
//        return;
//    }
//public:
//    vector<int> findMode(TreeNode* root) {
//        count = 0;
//        maxCount = 0;
//        pre = NULL;
//        result.clear();
//
//        searchBST(root);
//        return result;
//    }
//};
//int main() {
//    Solution s;
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(2);
//    root->left->left = new TreeNode(3);
//    root->left->right = new TreeNode(4);
//    root->right->left = new TreeNode(4);
//    root->right->right = new TreeNode(5);
//
//    vector<int> res = s.findMode(root);
//    for (int i = 0; i < res.size(); i++) {
//        cout << res[i] << " ";
//    }
//    cout << endl;   
//    return 0;
//}