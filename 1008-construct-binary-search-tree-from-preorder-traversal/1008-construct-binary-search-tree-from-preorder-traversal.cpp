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
    int i = 0;
    TreeNode* construct(vector<int> &preorder, long long upperBound){
        if(i==preorder.size() || preorder[i]>upperBound)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = construct(preorder, root->val);
        root->right = construct(preorder, upperBound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, LLONG_MAX);
    }
};