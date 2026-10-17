class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // --- Pruning step 1: check frequency of letters ---
        unordered_map<char, int> freqBoard, freqWord;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                freqBoard[board[i][j]]++;
        
        for (char c : word) freqWord[c]++;
        for (auto [ch, cnt] : freqWord) {
            if (freqBoard[ch] < cnt) return false; // impossible
        }

        // --- Pruning step 2: reverse word if beneficial ---
        if (freqBoard[word[0]] > freqBoard[word.back()])
            reverse(word.begin(), word.end());

        // Start DFS from matching cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0, m, n))
                    return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int index, int m, int n) {
        if (index == word.size()) return true;

        if (row < 0 || col < 0 || row == m || col == n ||
            board[row][col] != word[index]) return false;

        char c = board[row][col];
        board[row][col] = '!'; // mark visited

        bool found = dfs(board, word, row - 1, col, index + 1, m, n) ||
                     dfs(board, word, row + 1, col, index + 1, m, n) ||
                     dfs(board, word, row, col - 1, index + 1, m, n) ||
                     dfs(board, word, row, col + 1, index + 1, m, n);

        board[row][col] = c; // backtrack
        return found;
    }
};