class Solution {
public:
    struct DblEndedPQ {
        multiset<int> s;   

        int size() { return s.size(); }

        bool isEmpty() { return (s.size() == 0); }

        void insert(int x) { s.insert(x); }

        int getMin() { return *(s.begin()); }

        int getMax() { return *(s.rbegin()); }

        void deleteMin() {
            if (s.size() == 0)
                return;
            s.erase(s.begin());
        }

        void deleteMax() {
            if (s.size() == 0)
                return;
            auto it = s.end();
            it--;
            s.erase(it);
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        DblEndedPQ pq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            pq.insert(nums[i]);

            if (pq.size() > k) {     
                pq.s.erase(pq.s.find(nums[i - k]));  
            }

            if (i >= k - 1) {        
                ans.push_back(pq.getMax());
            }
        }

        return ans;
    }
};