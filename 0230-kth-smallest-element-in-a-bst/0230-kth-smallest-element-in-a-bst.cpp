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
 class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    void pushAll(TreeNode* root) {
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }
    int next(){
        TreeNode* node = st.top();
        st.pop();

        pushAll(node->right);
        return node->val;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        BSTIterator a(root);

        int kthMinVal = 0;
        while(k>0){
            kthMinVal = a.next();
            k--;
        }
        return kthMinVal;
    }
};