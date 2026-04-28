class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> arr;
        set<int> rem;
        for (auto it : grid) {
            for (auto i : it) {
                arr.push_back(i);
                rem.insert(i % x);
            }
        }
        if (rem.size() > 1) {
            return -1;
        }
        sort(arr.begin(), arr.end());

        int sz = arr.size();
        if(sz==1){
           return 0;
        }
        int mod = arr[sz / 2 - 1];
        int mod1 = arr[sz / 2 ];

        int cnt = 0,cnt1=0;
        for (auto it : arr) {
            cnt += abs(it - mod) / x;
        }
         for (auto it : arr) {
            cnt1 += abs(it - mod1) / x;
        }

        return min(cnt1,cnt);
    }
};