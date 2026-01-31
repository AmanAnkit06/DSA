class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        for(auto it:bookings){
            int firsti=it[0];
            int lasti=it[1];
            int seatsi=it[2];

            for(int i=firsti-1;i<lasti;i++){
                ans[i]+=seatsi;
            }

        }

        return ans;
    }
};