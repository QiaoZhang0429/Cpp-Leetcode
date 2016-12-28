class Solution {
private:
    int rslt;
    vector<vector<int>> jumps;
public:
    int numberOfPatterns(int m, int n) {
        rslt = 0;
        jumps.resize(10, vector<int>(10, 0));
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[3][9] = jumps[9][3] = 6;
        jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;
        int len = 1;
        for(int i = 1; i <= 9; i++){
            vector<bool> visited(10, false);
            visited[i] = true;
            backtracking(i, m, n, visited, len);
        }
        return rslt;
    }
    void backtracking(int start, int m, int n, vector<bool>& visited, int& len){
        if(len >= m)
            rslt++;
        if(len == n)
            return ;
        for(int i = 1; i <= 9; i++){
            int jump = jumps[start][i];
            if(!visited[i] && (jump == 0 || visited[jump])){
                len++;
                visited[i] = true;
                backtracking(i, m, n, visited, len);
                visited[i] = false;
                len--;
            }
        }
    }
};