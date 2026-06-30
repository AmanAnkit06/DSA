class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        set<int>st(b.begin(),b.end());
        
        vector<int>arr;
        for(int i:a){
            if(st.count(i)){
                arr.push_back(i);
            }
        }
        
        vector<int>lis;
        for(int i:arr){
            auto it=lower_bound(lis.begin(),lis.end(),i);
            if(it==lis.end()){
                lis.push_back(i);
            }else{
                *it=i;
            }
        }
        
        return a.size()-lis.size()+b.size()-lis.size();
    }
};