class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
    	stack<TreeNode*> stk;
    	while(root){
    		stk.push(root);
    		root = root->left;
    	}
    	TreeNode* newroot = stk.top();
    	TreeNode* cur = stk.top();
    	stk.pop();
    	while(!stk.empty()){
    		cur->left = stk.top()->right;
    		cur->right = stk.top();    		
    		stk.top()->left = stk.top()->right = NULL;  
    		cur = stk.top(); 		
    		stk.pop();
    	}
    	return newroot;
    }
};