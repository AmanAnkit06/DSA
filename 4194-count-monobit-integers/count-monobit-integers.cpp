class Solution {
public:
    int check(int n) {
        set<int> st;
        while (n > 0) {
            st.insert(n % 2);
            n /= 2;
        }
        return st.size();
    }
    int countMonobit(int n) {
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (check(i) == 1) {
                ans++;
            }
        }
        return ans;
    }
};