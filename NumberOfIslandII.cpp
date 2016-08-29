
/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/
class UnionFind{
private:
	vector<int> dSet;
	int count;
	int m, n;
public:
	UnionFind(int m, int n) : m(m), n(n){
		dSet.resize(m * n, -1);
		count = 0;
	}
	void addPosition(int i, int j){
		dSet[i*n+j] = i*n+j;
		count++;
	}
	void union(int a, int b){
		int root1 = find(a);
		int root2 = find(b);
		if(root1 == -1 || root2 == -1)
			return ;
		if(root1 == root2)
			return ;
		for(int i = 0; i < dSet.size(); i++){
			if(dSet[i] == root2)
				dSet[i] = root1;
		}
		count--;
	}
	void find(int a){
		return dSet[a];
	}
	int getCount()
		return count;
};
class Solution {
private:
	vector<pair<int, int>> dist{{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    	vector<int> rslt;
    	UnionFind uf(m, n);
    	for(auto p:positions){
    		uf.addPosition(p.first, p.second);
    		for(auto d:dist){
    			int x = p.first + d.first;
    			int y = p.second + d.second;
    			if(x < 0 || x >= m || y < 0 || y >= n)
    				continue;
    			uf.union(p.first*n+p.second, x*n+y);
    		}
    		rslt.push_back(uf.getCount());
    	}
    	return rslt;
    }
};