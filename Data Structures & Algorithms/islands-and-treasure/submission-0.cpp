class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            auto curr = q.front(); q.pop();    
            int r = curr.first, c = curr.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + direction[i][0];
                int nc = c + direction[i][1];
                if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] != INT_MAX) { continue;}
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
            



        }


        
    }
};
