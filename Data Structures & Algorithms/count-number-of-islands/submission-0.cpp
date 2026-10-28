// Use the provided grid, establish its dimensions, and initialize an island counter.
// Define the four directions for checking neighboring cells.

// Loop through every row and column.
// Whenever a cell contains '1', call BFS to visit its entire island.
// Increment the island counter once for that whole island.
// This BFS uses a queue and loops, not recursion.
// Return the total number of islands.

// In BFS, create a queue holding pairs of row and column coordinates.
// Mark the starting cell as '0' (visited), then push its coordinates.

// While the queue isn't empty, copy the FRONT coordinate pair into a variable.
// Pop that same pair from the FRONT of the queue, not the back.
// The saved copy lets us use those coordinates after removing the queue entry.
// Popping a queue entry does not remove a grid cell.

// Extract the current cell's row and column from the saved pair.
// Loop through the four directions to calculate each neighbor's coordinates.

// Check that the neighbor's row and column are inside the grid.
// Then check that the neighbor contains '1' (unvisited land).
// Push that neighbor's coordinates into the queue for later processing.
// Immediately mark it as '0' so it won't be queued or counted again.

// When the queue becomes empty, the entire island has been visited.

class Solution {
    int direction[4][2] = {{1,0}, {-1, 0}, {0,1}, {0,-1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size(), COL = grid[0].size();
        int islands = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == '1') {
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }
        
        return islands;
        
    }

    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int,int>> q;
        grid[r][c] = '0';
        q.push({r, c});

        while(!q.empty()) {
            auto node = q.front(); q.pop();
            int row = node.first;
            int col = node.second;
                for(int i = 0; i < 4; i++) {
                    int nr = row + direction[i][0];
                    int nc = col + direction[i][1];
                    if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1') {
                        q.push({nr, nc});
                        grid[nr][nc] = '0';
                    }
                }
        }
    }
};
