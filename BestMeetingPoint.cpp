class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        int rowP = rows[(int)rows.size() / 2];
        int colP = cols[(int)cols.size() / 2];
        int dist = 0;
        for(auto r:rows)
            dist += abs(r - rowP);
        for(auto c:cols)
            dist += abs(c - colP);
        return dist;
    }
};
//Manhattan's distance : independent in each dimension
//Median : odd - middle, even - any one of the middle two
//proof : can not be outside each pair, triangle theorem