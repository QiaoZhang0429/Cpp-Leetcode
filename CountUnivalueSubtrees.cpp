Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
private:
	int count;
public:
    int countUnivalSubtrees(TreeNode* root) {
    	count = 0;
    	unival(root);
    	return count;
    }
    bool unival(TreeNode* root){
    	if(!root)
    		return true;
    	if(unival(root->left) && unival(root->right)){
    		if(root->left && root->left->val != root->val)
    			return false;
    		if(root->right && root->right->val != root->val)
    			return false;
    		count++;
    		return true;
    	}
    	return false;
    }
};