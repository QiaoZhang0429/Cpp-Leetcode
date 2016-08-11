//O(logn) for both update and getsum
#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> bit;
    vector<int> record;
public:
    NumArray(vector<int> &nums) {
        record = nums;
        bit.resize(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++)
            add(i+1, nums[i]);
    }
    
    void add(int pos, int dif){
        while(pos < bit.size()){
            bit[pos] += dif;
            pos += lowbit(pos);
        }
    }

    void update(int pos, int val) {
        add(pos+1, val-record[pos]);
        record[pos] = val;
    }
    
    int getSum(int pos){
        int sum = 0;
        while(pos > 0){
            sum += bit[pos];
            pos -= lowbit(pos);
        }
        return sum;
    }

    int sumRange(int i, int j) {
        return i == 0? getSum(j+1) : getSum(j+1) - getSum(i);
    }
    
    int lowbit(int pos){
        return pos & (-pos);
    }
};

class TreeNode{
public:
	int start;
	int end;
	int sum;//range sum inclusive
	TreeNode* left;
	TreeNode* right;
	TreeNode() : start(0), end(0), sum(0), left(NULL), right(NULL) {}
	TreeNode(int s, int e) : start(s), end(e), sum(0), left(NULL), right(NULL) {}
};
class NumArray {
private:
	TreeNode* root;
public:
	NumArray(vector<int> &nums){
		if(nums.size() == 0)
			return ;
		root = buildTree(0, nums.size()-1, nums);
	}
	void update(int pos, int val){
		updateTree(root, pos, val);
	}
	int sumRange(int i, int j) {
		return queryTree(root, i, j);
	}
	TreeNode* buildTree(int start, int end, vector<int>& nums){
		root = new TreeNode(start, end);
		if(start == end){
			root->sum = nums[start];
			return root;
		}
		int middle = start + (end - start) / 2;
		root->left = buildTree(start, middle, nums);
		root->right = buildTree(middle+1, end, nums);
		root->sum = root->left->sum + root->right->sum;
		return root;
	}
	void updateTree(TreeNode* root, int pos, int val){
		if(root == NULL)
			return ;
		if(root->start == pos && root->end == pos){
			root->sum = val;
			return ;
		}
		int middle = root->start + (root->end - root->start) / 2;
		if(pos <= middle)
			updateTree(root->left, pos, val);
		else
			updateTree(root->right, pos, val);
		root->sum = root->left->sum + root->right->sum;
	}
	int queryTree(TreeNode* root, int i, int j){
		if(root == NULL)
			return 0;
		if(root->start == i && root->end == j)
			return root->sum;
		int middle = root->start + (root->end - root->start) / 2;
		if(j <= middle)
			return queryTree(root->left, i, j);
		else if(i >= middle + 1)
			return queryTree(root->right, i, j);
		else
			return queryTree(root->left, i, middle) + queryTree(root->right, middle+1, j);
	}
};