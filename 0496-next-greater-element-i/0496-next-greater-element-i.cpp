class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> ans(m,0);
        map<int,int> mp;
        stack<int> stk;
        for(int i=0;i<n;i++)
        {
            int val=nums2[i];
            while(!stk.empty() && stk.top()<val)
            {
                mp[stk.top()]=val;
                stk.pop();
            }
            stk.push(val);
        }
        while(!stk.empty())
        {
            int x=stk.top();
            mp[x]=-1;
            stk.pop();
        }
        for(int i=0;i<m;i++)
        {
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};