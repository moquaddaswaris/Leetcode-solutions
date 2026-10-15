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
    bool reverse = true;
    // reverse = true (means before)
    //reverse = false (means next)
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* root) {
        while(root != NULL){
            st.push(root);
            reverse ? root = root->right : root = root->left;
        }
    }
    int next() {
        TreeNode* temp = st.top();
        st.pop();

        reverse ? pushAll(temp->left) : pushAll(temp->right);
        return temp->val;
    }
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int a = l.next();
        int b = r.next();
        while(a<b){
            if(a+b == k) return true;
            else if(a+b < k) a = l.next();
            else b = r.next();
        }
        
        return false;
    }
};