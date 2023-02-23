class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n);
        map<int,int> mp;
        for(int i=n-1;i>=0;i--)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                mp[nums[i]]++;
                nums.erase(nums.begin()+i);
            }
            else
            {
                mp[nums[i]]=1;
            }
        }
        sort(nums.begin(),nums.end());
        //reverse(nums.begin(),nums.end());
        dp[0]=nums[0]*mp[nums[0]];
        if(abs(nums[1]-nums[0])==1)
        {
            dp[1]=max(dp[0],nums[1]*mp[nums[1]]);
        }
        else
        {
            dp[1]=dp[0]+nums[1]*mp[nums[1]];
        }
        n=nums.size();
        for(int i=2;i<n;i++)
        {
            if(abs(nums[i]-nums[i-1])==1)
            {
                dp[i]=max(dp[i-1],nums[i]*mp[nums[i]]+dp[i-2]);
            }
            else
            {
                dp[i]=dp[i-1]+mp[nums[i]]*nums[i];
            }
        }
        return dp[n-1];
    }
};