class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            dp[i]=max(nums[i],dp[i+1]+nums[i]);
        }
        int ans=INT_MIN;
        for(auto x:dp)
        {
            ans=max(x,ans);
        }
        return ans;
    }
};