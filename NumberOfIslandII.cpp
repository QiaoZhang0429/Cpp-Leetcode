
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
class DisjointSet{
private:
    vector<int> a;
    int count;
public:
    DisjointSet(int n){
        for(int i = 0; i < n; i++)
            a.push_back(-1);
        count = 0;
    }
    void _insert(int x){
        a[x] = x;
        count++;
    }
    bool _union(int x, int y){
        if(a[y] == -1)
            return false;
        int root1 = _find(x);
        int root2 = _find(y);
        if(root1 == root2)
            return false;
        a[root1] = root2;
        count--;
        return true;
    }
    int _find(int x){
        int cur = x;
        while(cur != a[cur])
            cur = a[cur];
        int root = cur;
        cur = x;
        while(cur != a[cur]){
            int tmp = a[cur];
            a[cur] = root;
            cur = tmp;
        }
        return root;
    }
    int _getCount(){
        return count;
    }
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> rslt;
        vector<pair<int, int>> neighbor = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        DisjointSet ds(m*n);
        int numIslands = 0;
        for(auto p:positions){
            ds._insert(p.first*n+p.second);
            for(auto e:neighbor){
                int x = p.first + e.first;
                int y = p.second + e.second;
                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                ds._union(p.first*n+p.second, x*n+y);
            }
            rslt.push_back(ds._getCount());
        }
        return rslt;
    }
};