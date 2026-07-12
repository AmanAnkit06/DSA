class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        set<int> st(arr.begin(), arr.end());
        map<int, int> mp;
        int c = 1;
        vector<int> ans;
        for (int i : st) {
            mp[i] = c;
            c++;
        }

        for (int i : arr) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};