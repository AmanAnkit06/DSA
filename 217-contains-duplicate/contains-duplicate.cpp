class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        //using set------
        
        //Time complexity O(n)--
        //Space complexity O(n)---
        set<int> st;
        for (int i : nums) {
            if (st.find(i) != st.end())
                return true;
            st.insert(i);
        }

        return false;
    }
};