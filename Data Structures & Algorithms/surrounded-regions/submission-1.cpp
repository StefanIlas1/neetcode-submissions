class Solution {
    int directions[4][2] = {{1, 0}, {-1,0}, {0,1}, {0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();
        for(int r = 0; r < ROWS; r++) {
            if(board[r][0] == 'O') { capture(board,r, 0);}
            if(board[r][COLS - 1] == 'O') {capture(board, r, COLS - 1);}
        }

        for(int c = 0; c < COLS; c++) {
            if(board[0][c] == 'O') { capture(board,0,c);}
            if(board[ROWS - 1][c] == 'O') { capture(board, ROWS - 1, c);}
        }

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(board[r][c] == 'O') { board[r][c] = 'X';}
                else if(board[r][c] == 'T') { board[r][c] = 'O';}
            }
        }


        
    }

private:
    void capture(vector<vector<char>>& board, int r, int c) {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O') 
        { return;}

        board[r][c] = 'T';
        for(int i = 0; i < 4; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];

            capture(board, nr, nc);
        }

    }



};
