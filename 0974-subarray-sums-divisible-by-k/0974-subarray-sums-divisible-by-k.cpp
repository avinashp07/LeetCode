class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        int currSum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            currSum=(currSum+nums[i])%k;
            if(currSum<0) currSum+=k;
            if(mp.find(currSum%k)!=mp.end())
            {
                ans+=mp[currSum%k];
                mp[currSum]++;
            }
            else
            {
                if(mp.find(currSum)!=mp.end()) mp[currSum]++;
                else
                mp[currSum]=1;
            }
        }
        return ans;
    }
};