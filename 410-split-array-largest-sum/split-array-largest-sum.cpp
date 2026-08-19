class Solution {
public:
    int helper(vector<int>& nums, int thresold, int k) {
        int sum = 0;
        int k1 = 1;

        for (int i = 0; i < nums.size(); i++) {
           if (sum + nums[i] > thresold) {
                k1++;
                sum = nums[i];

                if (k1 > k)
                    return false;
            } else {
                sum += nums[i];
            }
        }

        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int high = accumulate(nums.begin(), nums.end(), 0);
        int low = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = (low +high)/ 2;
            if(helper(nums,mid,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};