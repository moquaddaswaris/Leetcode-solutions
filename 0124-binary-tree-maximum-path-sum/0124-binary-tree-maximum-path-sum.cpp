/**
 * Definition for a binary tree root.
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
    int maxSum = INT_MIN;
    int findMaxSum(TreeNode* root){
        if (!root) return 0;

        int leftSum = max(0, findMaxSum(root->left));
        int rightSum = max(0, findMaxSum(root->right));

        int currentPath = root->val + leftSum + rightSum;
        maxSum = max(maxSum, currentPath);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        findMaxSum(root);
        return maxSum;
    }
};