class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int maxP=0;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            int crtP=prices[i]-buy;
            maxP=max(maxP,crtP);
            if(crtP<0){
                buy=prices[i];
            }
        }
        
        return maxP;
    }
};
