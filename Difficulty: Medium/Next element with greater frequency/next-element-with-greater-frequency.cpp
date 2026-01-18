class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int,int> freq;
        for (int x : arr) {
            freq[x]++;
        }
        
        vector<int> ans(n, -1);
        stack<int> st; 
        
        for (int i = n - 1; i >= 0; i--) {
            // Remove elements with freq <= current
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }
            
            if (!st.empty()) {
                ans[i] = arr[st.top()];
            }
            
            st.push(i);
        }
        
        return ans;
    }
};
