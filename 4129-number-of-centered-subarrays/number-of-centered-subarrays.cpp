class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int crt_sum = nums[i];
            set<int> st;
            st.insert(nums[i]);
            cnt++;
            for (int j = i + 1; j < nums.size(); j++) {
                crt_sum += nums[j];
                st.insert(nums[j]);

                if (st.find(crt_sum) != st.end()) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};