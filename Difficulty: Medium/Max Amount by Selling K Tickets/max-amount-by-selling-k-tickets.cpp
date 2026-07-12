class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        
        priority_queue<int>pq;
        for(int i:arr){
            pq.push(i);
        }
        int mod=1e9+7;
        
        long long   ans=0;
        
        while(k!=0 && !pq.empty()){
             int ticket=pq.top();
            ans=(((ans%mod)+ticket)%mod);
           
            pq.pop();
            ticket--;
            k--;
            if(ticket>0){
                pq.push(ticket);
            }
        }
        
        return ans;
    }
};