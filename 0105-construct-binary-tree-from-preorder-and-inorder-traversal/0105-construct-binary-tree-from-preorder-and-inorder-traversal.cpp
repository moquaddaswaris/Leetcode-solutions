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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return build(preorder, preIndex, 0, inorder.size() - 1, inMap);
    }

    TreeNode* build(vector<int>& preorder, int& preIndex, int inStart, int inEnd, map<int, int>& inMap){
        if(inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        int inRoot = inMap[root->val];

        root->left = build(preorder, preIndex, inStart, inRoot - 1, inMap);
        root->right = build(preorder, preIndex, inRoot + 1, inEnd, inMap);

        return root;
    }
};