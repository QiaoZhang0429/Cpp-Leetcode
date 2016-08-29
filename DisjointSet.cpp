class TreeNode{
	int val;
	TreeNode* prev;
	TreeNode(int v) : val(v), prev(NULL) {}
};
class DisjointSet{//up tree
private:
	int size;
	vector<TreeNode*> dSet;
	int count;
public:
	DisjointSet(int n){
		size = n;
		count = n;
		for(int i = 0; i < size; i++)
			dSet.push_back(new TreeNode(i));
	}
	void union(TreeNode* a, TreeNode* b){
		TreeNode* root1 = find(a);
		TreeNode* root2 = find(b);
		if(root1 == root2)
			return ;
		root2->prev = root1;
		count--;
	}
	void find(TreeNode* a){
		if(a == NULL || a->prev == NULL)
			return a;
		TreeNode* root = a;
		while(root->prev)
			root = root->prev;
		TreeNode* cur = a;
		while(cur != root)
			cur->prev = root;
		return root;
	}
};

class DisjointSet{//array
private:
	int size;
	int count;
	vector<int> dSet;
public:
	DisjointSet(int n){
		size = n;
		count = n;
		for(int i = 0; i < size; i++)
			dSet.push_back(i);
	}
	void union(int a, int b){//O(n)
		int root1 = find(a);
		int root2 = find(b);
		if(root1 == root2)
			return ;
		for(int i = 0; i < size; i++){
			if(dSet[i] == root1)
				dSet[i] = root2;
		}
		count--;
	}
	void find(int a){//O(1)
		return dSet[a];
	}
	int getCount(){
		return count;
	}
};

class DisjointSet{//array
private:
	int size;
	int count;
	vector<int> dSet;
public:
	DisjointSet(int n){
		size = n;
		count = n;
		for(int i = 0; i < size; i++)
			dSet.push_back(i);
	}
	void union(int a, int b){//O(logn)
		int root1 = find(a);
		int root2 = find(b);
		dSet[root1] = root2;
	}
	void find(int a){//O(logn)
		while(dSet[a] != a){
			int tmp = dSet[a];
			dSet[a] = dSet[dSet[a]];
			a = tmp;
		}
		return a;
	}
	int getCount(){
		int count = 0;
		for(int i = 0; i < size; i++)
			if(i == dSet[i])
				count++;
		return count;
	}
};