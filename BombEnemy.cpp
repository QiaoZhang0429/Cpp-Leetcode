class Solution {
public:
    //brute force, n^3
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> count(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            int head = 0;
            int tail = 0;
            for(int j = 0; j < n; j++){
                count[i][j] = grid[i][j] != '0' ? 0 : count[i][j]+head;
                count[i][n-1-j] = grid[i][n-1-j] != '0' ? 0 : count[i][n-1-j]+tail;
                head = grid[i][j] == 'W' ? 0 : (grid[i][j] == 'E' ? head+1 : head);
                tail = grid[i][n-1-j] == 'W' ? 0 : (grid[i][n-1-j] == 'E' ? tail+1 : tail);
            }
        }
        for(int j = 0; j < n; j++){
            int head = 0;
            int tail = 0;
            for(int i = 0; i < m; i++){
                count[i][j] = grid[i][j] != '0' ? 0 : count[i][j]+head;
                count[m-1-i][j] = grid[m-1-i][j] != '0' ? 0 : count[m-1-i][j]+tail;
                head = grid[i][j] == 'W' ? 0 : (grid[i][j] == 'E' ? head+1 : head);
                tail = grid[m-1-i][j] == 'W' ? 0 : (grid[m-1-i][j] == 'E' ? tail+1 : tail);
            }
        }
        int rslt = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                rslt = max(rslt, count[i][j]);
        return rslt;
    }
};