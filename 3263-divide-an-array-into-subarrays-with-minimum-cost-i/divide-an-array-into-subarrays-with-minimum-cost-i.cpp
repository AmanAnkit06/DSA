class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum=INT_MAX;
        for(int i=1;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                sum=min(sum,nums[i]+nums[j]);
            }
        }

        return sum+nums[0];
    }
};