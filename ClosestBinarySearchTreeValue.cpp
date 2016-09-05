class Solution {  
public:
    int closestValue(TreeNode* root, double target) { 
    	TreeNode* cur = root;
    	int closest;
    	double dist = DBL_MAX;
    	while(cur){
    		if(abs(target - (double)cur->val) < dist){
    			dist = abs(target - (double)cur->val);
    			closest = cur->val;
    		}
    		if(cur->val == target)
    			return target;
    		if(cur->val > target)
    			cur = cur->left;
    		else
    			cur = cur->right;
    	}
    	return closest;
    }
};
//basic : dfs , check each node, need cut branch