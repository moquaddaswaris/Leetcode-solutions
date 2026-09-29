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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==NULL) return ans;
        
        deque<TreeNode*> dq;
        dq.push_front(root);

        bool leftToRight = true;
        while (!dq.empty()){
            int n = dq.size();
            vector<int> level;

            // building level by level
            for(int i=0; i<n; i++){
                if(leftToRight){
                    TreeNode* temp = dq.front();
                    dq.pop_front();

                    level.push_back(temp->val);
                    if (temp->left) dq.push_back(temp->left);
                    if (temp->right) dq.push_back(temp->right);
                }
                else{
                    TreeNode* temp = dq.back();
                    dq.pop_back();

                    level.push_back(temp->val);
                    if (temp->right) dq.push_front(temp->right);
                    if (temp->left) dq.push_front(temp->left);
                }
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};