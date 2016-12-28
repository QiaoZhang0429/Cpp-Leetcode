class Solution {
private:
    vector<pair<int, int>> neighbor = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0)
            return ;
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[0].size(); j++){
                if(rooms[i][j] == 0)
                    bfs(rooms, i, j);
            }
        }
    }
    void bfs(vector<vector<int>>& rooms, int m, int n){
        queue<pair<int, int>> q;
        q.push(make_pair(m, n));
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            for(auto p:neighbor){
                int x = tmp.first + p.first;
                int y = tmp.second + p.second;
                if(x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size() || rooms[x][y] <= rooms[tmp.first][tmp.second]+1)//last condition important, avoid visit visited node
                    continue;
                q.push(make_pair(x, y));
                rooms[x][y] = rooms[tmp.first][tmp.second]+1;
            }
        }
    }
};