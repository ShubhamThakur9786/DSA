class Solution {
public:
    bool solve(int row, int col, vector<vector<char>>& board, string word, int idx, int n, int m) {
        if(idx == word.size()) {
            return true;
        }

        if(row < 0 || row >= n || col < 0 || col >= m || board[row][col] == '$' || board[row][col] != word[idx]) {
            return false;
        }


        char temp = board[row][col];
        board[row][col] = '$';

        bool up = solve(row-1, col, board, word, idx+1, n, m);
        bool down = solve(row+1, col, board, word, idx+1, n, m);
        bool left = solve(row, col-1, board, word, idx+1, n, m);
        bool right = solve(row, col+1, board, word, idx+1, n, m);

        board[row][col] = temp;

        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(solve(i, j, board, word, 0, n, m)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};