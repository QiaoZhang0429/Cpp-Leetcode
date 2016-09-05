//with parent

//without parent

class Solution {   
public:   
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) { 
    	TreeNode* cur = root;
    	TreeNode* successor;
    	while(cur){
    		if(cur->val == p->val)
    			break;
    		if(cur->val < p->val)
    			cur = cur->right;
    		else{
    			successor = cur;
    			cur = cur->left;
    		}
    	}
    	if(cur != p)
    		return NULL;//p is not in the tree
    	if(!p->right)
    		return successor;//the nearest root up along from p
    	cur = p->right;
    	while(cur->left){
    		cur = cur->left;
    	}
    	return cur;
    }
};