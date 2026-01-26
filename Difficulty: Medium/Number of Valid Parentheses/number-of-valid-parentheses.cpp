class Solution {
  public:
  
    int countP(int open,int close){
        
        if(open < 0 || close < 0){
            return 0;
        }
        
        if(open < close){
            return 0;
        }
        if(open == 0 && close == 0){
            return 1;
        }
        
        return countP(open - 1 , close)+countP(open , close - 1);
    }
    int findWays(int n) {
        // code here
        if(n%2==1)return 0;
        
        return countP(n/2,n/2);
    }
};