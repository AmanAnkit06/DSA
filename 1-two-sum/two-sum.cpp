class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // apply brute force--------
      /*  for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }*/

        //apply optimal using map ds----
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            auto it=mp.find(target-nums[i]);
            if(it!=mp.end()){
                return {mp[target-nums[i]],i};
            }
             mp[nums[i]]=i;
        }
        
        return {};
    }
};