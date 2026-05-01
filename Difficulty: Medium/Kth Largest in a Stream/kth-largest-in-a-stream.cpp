class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size()==k){
                ans.push_back(pq.top());
               
            }else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};