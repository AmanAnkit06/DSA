class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int cnt=0;
        vector<int> temp=arr;
       sort(arr.begin(),arr.end());
       for(int i=0;i<arr.size();i++){
           if(arr.back()==temp[i])cnt=i+1;
       }
       
       return (cnt==arr.size())?0:cnt;
    }
};
