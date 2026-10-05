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

//  vector<int> ans;
//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty()){
//             int n = q.size();
//             for(int i=0; i<n; i++){
//                 TreeNode* curr = q.front();
//                 q.pop();

//                 if(i == n-1) ans.push_back(curr->val);
//                 if (curr->left) q.push(curr->left);
//                 if (curr->right) q.push(curr->right);
//             }
//         }
//         return ans;
class Solution {
public:
    vector<int> ans;
    void reversePreorder(TreeNode* root, int level){
        if(!root) return;
        if(ans.size() == level) ans.push_back(root->val);

        reversePreorder(root->right, level+1);
        reversePreorder(root->left, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        reversePreorder(root, 0);
        return ans;
    }
};