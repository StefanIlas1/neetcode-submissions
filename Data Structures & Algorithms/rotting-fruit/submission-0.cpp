class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int ROWS = grid.size(), COLS = grid[0].size();
        int fresh = 0;
        int time = 0;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 1) {
                    fresh++;
                }
                if(grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }
        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(fresh > 0 && !q.empty()) {
            int length = q.size();
            for(int i = 0; i < length; i++) {
            auto curr = q.front(); q.pop();
            int r = curr.first, c = curr.second;

            for(int i = 0; i < 4; i++) {
                int nr = r + direction[i][0];
                int nc = c + direction[i][1];
                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                }
            }
        }
        time++;

            
        }

        return fresh == 0 ? time : -1;
        } 
};
