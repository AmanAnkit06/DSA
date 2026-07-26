class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int n = series1.size();
        int m = series2.size();

        int i = 0, j = 0;

        while (i < n && j < m) {
            int t1 = series1[i][0];
            int t2 = series2[j][0];

            int mini = min(t1, t2);
            int v;
            if(t1==t2){
                v = series1[i][1] + series2[j][1];
                i++;j++;
            }
            else if (t1 == mini) {
                if (j < m) {
                    v = series1[i][1] + series2[j][1];
                } else {
                    v = series1[i][1];
                }
                i++;
            } else {
                if (i < n) {
                    v = series2[j][1] + series1[i][1];
                } else {
                    v = series1[j][1];
                }
                j++;
            }

            ans.push_back({mini, v});
        }
        while (i < n) {
            ans.push_back(series1[i]);
            i++;
        }
        while (j < m) {
            ans.push_back(series2[j]);
            j++;
        }

        return ans;
    }
};