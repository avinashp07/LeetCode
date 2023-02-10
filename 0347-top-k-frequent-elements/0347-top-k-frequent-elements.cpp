class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int>b)
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                mp[nums[i]]++;
            }
            else
            {
                mp[nums[i]]=1;
            }
        }
        vector<pair<int,int>> v;
        for(auto x:mp)
        {
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};