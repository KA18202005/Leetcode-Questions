class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int r, int c, int dr, int dc) {
        int m = board.size();
        int n = board[0].size();
        int len = word.size();
        int br = r - dr;
        int bc = c - dc;
        if(br >= 0 && br < m && bc >= 0 && bc < n && board[br][bc] != '#') return false;
        for(int i = 0; i < len; i++) {
            int nr = r + i * dr;
            int nc = c + i * dc;
            if(nr < 0 || nr >= m || nc < 0 || nc >= n) return false;
            if(board[nr][nc] == '#') return false;
            if(board[nr][nc] != ' ' && board[nr][nc] != word[i]) return false;
        }
        int ar = r + len * dr;
        int ac = c + len * dc;
        if(ar >= 0 && ar < m && ac >= 0 && ac < n && board[ar][ac] != '#') return false;
        return true;
    }

    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(board[r][c] == '#') continue;
                for(int d = 0; d < 4; d++) {
                    if(check(board, word, r, c, dr[d], dc[d])) return true;
                }
            }
        }
        return false;
    }
};