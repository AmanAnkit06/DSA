class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int>mp;
       
        for(int i=0;i<numbers.size();i++){
            int sum=target-numbers[i];
            if(mp.count(numbers[i])){
                return {mp[numbers[i]],i+1};
            }
            mp[sum]=i+1;
        }
        return {};
    }
};