class Solution {  
private:
	int count;
public:  
	int largestBSTSubtree(TreeNode* root) { 
		count = 0;
		dfs(root);
		return count;
	}
	vector<int> dfs(TreeNode* root){
		if(root == NULL)
			return vector<int>{0, INT_MAX, INT_MIN};
		auto left = dfs(root->left);//count, min, max
		auto right = dfs(root->right);
		if(root->val > left[2] && root->val < right[1]){
			count = max(count, 1+left[0]+right[0]);
			return vector<int>{1+left[0]+right[0], min(root->val, left[1]), max(root->val, right[2])};
		}
		return vector<int>{0, INT_MIN, INT_MAX};
	}
}; 