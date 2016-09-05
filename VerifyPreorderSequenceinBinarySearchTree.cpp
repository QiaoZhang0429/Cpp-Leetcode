/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
*/
class Solution {
public:
    bool verifyPreorder(vector<int> preorder) {
    	stack<int> stk;
    	int lowbound = INT_MIN;
    	for(auto val:preorder){
    		if(val < lowbound)
    			return false;
    		while(!stk.empty() && val > stk.top()){//right node
    			lowbound = stk.top();
    			stk.pop();
    		}    		
    		stk.push(val);
    	}
    	return true;
    }
};
//decreasing order : travel down along left
//stop decreasing : right node of one visited node, the following should be greater than its parent, the parent can be identified with a stack and as the last pop

class Solution {
public:
    bool verifyPreorder(vector<int> preorder) {
    	int index = -1;
    	int lowbound = INT_MIN;
    	for(auto val:preorder){
    		if(val < lowbound)
    			return false;
    		while(index >= 0 && val > preorder[index]){//right node
    			lowbound = preorder[index--];
    		}    		
    		preorder[++index] = val;
    	}
    	return true;
    }
};