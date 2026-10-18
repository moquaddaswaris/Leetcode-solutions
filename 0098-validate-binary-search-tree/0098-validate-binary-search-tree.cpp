/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, long long minRange, long long maxRange){
        if(!root) return true;
        if(root->val<= minRange || root->val>=maxRange)
            return false;
        
        return check(root->left, minRange, root->val) &&
                check(root->right, root->val, maxRange);
    }

    bool isValidBST(TreeNode* root) {
       return check(root, LLONG_MIN, LLONG_MAX);
    }
};