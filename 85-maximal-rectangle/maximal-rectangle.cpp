class Solution {
    int f(int n, vector<int> ar) {
        vector<int> left, right;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && ar[st.top()] >= ar[i]) {
                st.pop();
            }
            if (st.empty()) {
                left.push_back(0);
            } else {
                left.push_back(st.top() + 1);
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && ar[st.top()] >= ar[i]) {
                st.pop();
            }
            if (st.empty()) {
                right.push_back(n - 1);
            } else {
                right.push_back(st.top() - 1);
            }
            st.push(i);
        }
        reverse(right.begin(), right.end());
        for (auto x : left) {
            cout << x << " ";
        }
        cout << endl;
        for (auto x : right) {
            cout << x << " ";
        }
        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            area = max(area, ar[i] * (right[i] - left[i] + 1));
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ar(col);
        int area = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    ar[j]++;
                } else {
                    ar[j] = 0;
                }
            }
            area = max(area, f(col, ar));
        }
        for (auto x : ar) {
            cout << x << " ";
        }
        cout << endl;
        return area;
    }
};