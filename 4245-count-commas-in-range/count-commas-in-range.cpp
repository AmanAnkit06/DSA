class Solution {
public:
    int countCommas(int n) {
        int ans=0;
        for(int i=1000;i<=n;i++){
            string str=to_string(i);
            int n=str.size();
            ans+=(n%3==0)?(n/3-1):n/3;
        }

        return ans;
    }
};