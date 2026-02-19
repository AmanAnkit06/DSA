class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
        for (auto& [key, value] : mp) {
            pq.push({value, key});

            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};