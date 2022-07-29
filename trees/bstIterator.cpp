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
    stack<TreeNode *> myStack;
    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
    
    int next() {
        TreeNode * node = myStack.top();
        myStack.pop();
        pushAll(node->right);
        return node->val;
    }
    
    
    void pushAll(TreeNode * node){
        // while(!node){
        //     myStack.push(node);
        //     node = node->left;
        // }
        for(; node!=NULL; myStack.push(node), node = node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
