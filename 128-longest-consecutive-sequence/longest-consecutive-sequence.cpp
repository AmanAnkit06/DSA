class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int> st(nums.begin(), nums.end());

        int cnt = 0;

        vector<int> arr;
        for (int i : st) {
            arr.push_back(i);
        }
        int temp = arr[0];
        cnt = 1;
        int maxi = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == 1) {
                cnt++;
            } else {
                maxi = max(maxi, cnt);
                cnt = 1;
            }
        }
        maxi = max(maxi, cnt);
        return maxi;
    }
};