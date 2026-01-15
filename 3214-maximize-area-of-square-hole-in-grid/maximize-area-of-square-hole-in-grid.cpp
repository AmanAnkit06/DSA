class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        int maxConsH = 1, maxConsV = 1;
        int cnt = 1;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i - 1] == 1) {
                cnt++;
            } else {

                cnt = 1;
            }
            maxConsH = max(maxConsH, cnt);
        }
        cnt = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i - 1] == 1) {
                cnt++;
            } else {

                cnt = 1;
            }
            maxConsV = max(maxConsV, cnt);
        }

        int side = min(maxConsH, maxConsV) + 1;

        return side * side;
    }
};