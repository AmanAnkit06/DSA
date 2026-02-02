class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int ans=INT_MIN;
        int crtSum=0;
        for(int i:arr){
            crtSum+=i;
            ans=max(ans,crtSum);
            if(crtSum<0){
                crtSum=0;
            }
        }
        
        return ans;
    }
};