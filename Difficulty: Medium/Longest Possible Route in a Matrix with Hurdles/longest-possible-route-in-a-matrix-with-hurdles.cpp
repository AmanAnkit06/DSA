class Solution {
	public:
	
	int dfs(vector<vector<int>> & mat, int x, int y, int xd, int yd) {
		if (x == xd && y == yd)
			return 0;
		
		mat[x][y] = 0;
		
		int ans = -1;
		
		int dx[] = {-1, 0, 1, 0};
		int dy[] = {0, 1, 0, -1};
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 0 && nx < mat.size() && ny >= 0 && ny < mat[0].size() && mat[nx][ny] == 1) {
				
				int cur = dfs(mat, nx, ny, xd, yd);
				if (cur != -1)
					ans = max(ans, cur + 1);
			}
		}
		
		mat[x][y] = 1; 
		
		return ans;
	}
	int longestPath(vector<vector<int>> & mat, int xs, int ys, int xd, int yd) {
		// code here
		if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
			return - 1;
		
		return dfs(mat, xs, ys, xd, yd);
	}
};
