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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});
        while(!q.empty()){
            int currSize = q.size();
            unsigned long long startIdx = q.front().second;

            for(int i=0; i<currSize; i++){
                TreeNode* curr = q.front().first;
                unsigned long long idx = q.front().second - startIdx;
                q.pop();

                if(i == currSize-1)
                    maxWidth = max(maxWidth, (int)(idx+1));

                if(curr->left) q.push({curr->left, 2*idx+1});
                if(curr->right) q.push({curr->right, 2*idx+2});
            }
        }

        return maxWidth;
    }
};