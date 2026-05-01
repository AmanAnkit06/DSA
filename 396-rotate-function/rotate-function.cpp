class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // brute -froce approach---

        /*
            int j=0;
            int n=nums.size();
            long long  maxi=INT_MIN;

            while(j<n){

                long long  sum=0;
                for(int i=0;i<n;i++){
                    sum+=i*nums[i];
                }
                maxi=max(maxi,sum);

                rotate(nums.rbegin(), nums.rbegin() + j, nums.rend());

                j++;
            }

            return maxi;
        */
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int prevSum = 0;
        for (int i = 0; i < n; i++) {
            prevSum += i * nums[i];
        }
        int maxi = prevSum;

        int i = 1;

        while (i < n) {
           
            int crtSum = prevSum + sum - n * nums[n - i];

            maxi = max(maxi, crtSum);
            prevSum = crtSum;
            i++;
        }

        return maxi;
    }
};