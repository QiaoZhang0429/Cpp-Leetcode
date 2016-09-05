class Solution{
private:
	int len;
public:
	int longestConsecutive(TreeNode* root){
		if(!root)
			return 0;
		len = 1;
		dfs(root, 1);
		return len;
	}
	void dfs(TreeNode* root, int c){
		if(root->left){
			if(root->left->val == root->val + 1){
				dfs(root->left, c+1);
				len = max(len ,c+1);
			}
			else
				dfs(root->left, 1);
		}
		if(root->right){
			if(root->right->val == root->val + 1){
				dfs(root->right, c+1);
				len = max(len ,c+1);
			}
			else
				dfs(root->right, 1);
		}
	}
};