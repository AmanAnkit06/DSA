class Solution {
  public:
    int n, m;
    int row[4] = {0, -1, 0, 1};
    int col[4] = {1, 0, -1, 0};

    bool dfs(int r, int c, int idx, vector<vector<char>> &mat, string &word) {
       
        if (idx == word.size()) return true;

       
        if (r < 0 || c < 0 || r >= n || c >= m || mat[r][c] != word[idx])
            return false;

        char temp = mat[r][c];
        mat[r][c] = '#'; 

        for (int i = 0; i < 4; i++) {
            if (dfs(r + row[i], c + col[i], idx + 1, mat, word))
                return true;
        }

        mat[r][c] = temp; 
        return false;
    }

    bool isWordExist(vector<vector<char>> &mat, string &word) {
        n = mat.size();
        m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    if (dfs(i, j, 0, mat, word))
                        return true;
                }
            }
        }
        return false;
    }
};
