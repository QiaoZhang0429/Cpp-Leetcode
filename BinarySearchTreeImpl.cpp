class TreeNode{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	//TreeNode* parent;
	TreeNode() : left(NULL), right(NULL) {}
};

class BST{
private:
	TreeNode* root;
public:
	BST();
	getPredecessor();
	getSuccessor();
	erase();
	insert();
	size();
	find();
	clear();
	empty();

};