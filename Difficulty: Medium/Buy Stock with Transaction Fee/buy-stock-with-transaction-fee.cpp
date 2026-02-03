class Solution {
  public:
  
//   int helper(vector<int>&arr,int idx,int temp,int k,vector<vector<int>>&dp){
//       if(idx==arr.size()){
//           return 0;
//       }
//       if(dp[idx][temp]!=-1){
//           return dp[idx][temp];
//       }
      
//       int profit=0;
//       if(temp){
//           //for buy the stock
//           profit=max((-arr[idx]+helper(arr,idx+1,0,k,dp)),(0+helper(arr,idx+1,1,k,dp)));
//       }else{
          
//           //for sell the stock
//           profit=max((arr[idx]-k+helper(arr,idx+1,1,k,dp)),(0+helper(arr,idx+1,0,k,dp)));
//       }
      
//       return dp[idx][temp]=profit;
//   }
  
    int maxProfit(vector<int>& arr, int k) {
        // Code here
      int n=arr.size();
    //   vector<vector<int>>dp(n,vector<int>(2,-1));
       
    //   return helper(arr,0,1,k,dp);
       
       
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for (int i = n-1; i >= 0; i--) {
        dp[i][1] = max(
            -arr[i] + dp[i+1][0],
            dp[i+1][1]
        );
        dp[i][0] = max(
            arr[i] - k + dp[i+1][1],
            dp[i+1][0]
        );
    }
    return dp[0][1];
    
    
    
    
    }
};
