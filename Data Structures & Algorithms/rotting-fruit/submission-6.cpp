class Solution {
    //minimum number of minutes that must elapse until there are zero fresh fruits remaining
    //IF IMPOSSIBLE: return -1;
    //minimum minutes = minimum steps.... = minimum path = bfs
    //so we're going to start at 2 and work our way out...
        // once we see a 1 we'll auto convert it to 0.
        //if a 1 is not next to a 2/0( we'll see) then end and return the count.
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 1) {
                    fresh++;
                }
                if(grid[r][c] == 2) {
                    q.push({r,c});
                }
            }
        }

        int directions[4][2] = {{1, 0}, {-1,0}, {0,1}, {0, -1}};
        while( fresh > 0 && !q.empty()) {
            int length = q.size();
            for(int i = 0; i < length; i++) {
                auto node = q.front(); q.pop();
                
                int r = node.first;
                int c = node.second;

                for(int i = 0; i < 4; i++) {
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];
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
