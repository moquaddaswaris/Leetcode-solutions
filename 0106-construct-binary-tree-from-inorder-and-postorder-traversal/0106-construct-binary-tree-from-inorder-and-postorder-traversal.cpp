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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = build(postorder, postorder.size()-1, 0,
                               inorder, 0, inorder.size()-1, inMap);
        return root;
    }

    TreeNode* build(vector<int>& postorder, int postStart, int postEnd,
                    vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap) {

        if(postStart < postEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postStart]);

        int inRoot = inMap[root->val];
        int numsRight = inEnd - inRoot;

        root->right = build(postorder, postStart - 1, postStart - numsRight,
                            inorder, inRoot + 1, inEnd, inMap);
        root->left = build(postorder, postStart - numsRight - 1, postEnd,
                           inorder, inStart, inRoot - 1, inMap);

        return root;
    }
};