class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        vector<bool> dp(n,0);
        dp[n-1]=true;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==0) continue;
            if(i+nums[i]>=n-1 || dp[i+nums[i]]) dp[i]=true;
            else
            {
                for(int j=0;j<=nums[i];j++)
                if(dp[i+j]) dp[i]=true;
            }
        }
        for(auto x: dp) cout<<x<<" ";
        return dp[0];
    }
};