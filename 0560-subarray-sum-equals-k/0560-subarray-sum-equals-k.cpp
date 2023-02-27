class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1;
        int currSum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            int diff=currSum-k;
            if(mp.find(diff)!=mp.end())
            {
                ans+=mp[diff];
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