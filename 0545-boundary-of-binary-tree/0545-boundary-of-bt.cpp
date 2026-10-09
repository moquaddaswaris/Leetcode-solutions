/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
public:
    bool isLeaf(TreeNode* root){
        if(!root->left && !root->right) return true;

        return false;
    }

    void leftBoundary(TreeNode* root, vector<int> &ans){
        TreeNode* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left)
                curr = curr->left;
            else 
                curr = curr->right;
        }
    }

    void rightBoundary(TreeNode* root, vector<int> &ans){
        TreeNode* curr = root->right;
        vector<int> temp;

        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }

        for(int i=temp.size()-1; i>=0; i--)
            ans.push_back(temp[i]);
    }

    void leafNodes(TreeNode* root, vector<int> &ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }

        if(root->left) leafNodes(root->left, ans);
        if(root->right) leafNodes(root->right, ans);
    }

    vector <int> boundary(TreeNode* root){
    	vector<int> ans;

        ans.push_back(root->data);
        leftBoundary(root, ans);
        leafNodes(root, ans);
        rightBoundary(root, ans);

        return ans;
    }
};