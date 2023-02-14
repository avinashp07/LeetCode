class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        int longest=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            if(s.find(nums[i]-1)==s.end())
            {
                while(s.find(nums[i]+count)!=s.end())
                {
                    count++;
                }
                longest=max(count,longest);
            }
        }
        return longest;
    }
};