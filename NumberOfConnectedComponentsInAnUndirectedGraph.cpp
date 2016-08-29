class DisjointSet{
private:
	int count;
	int size;
	vector<int> dSet;
public:
	DisjointSet(int n){
		size = count = n;
		for(int i = 0; i < size; i++)
			dSet.push_back(i);
	}
	void union(int a, int b){
		int root1 = find(a);
		int root2 = find(b);
		if(root1 == root2)
			return ;
		for(int i = 0; i < size; i++)//path compression
			if(dSet[i] == root1)
				dSet[i] = root2;
		count--;
	}
	int find(int a){
		return dSet[a];
	}
	int getCount(){
		return count;//or check the number of dSet[i] == i
	}
};

class Solution{
public:
    int countComponents(int n, vector<pair<int, int>> edges){
    	DisjointSet ds(n);
    	for(auto e:edges){
    		ds.union(e.first, e.second);
    	}
    	return ds.getCount();
    }
};