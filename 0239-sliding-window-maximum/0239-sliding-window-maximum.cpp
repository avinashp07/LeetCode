class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        deque<int> dq;
        int l=0,r=0;
        while(r<n)
        {
            while(dq.size() && nums[dq.back()]<nums[r])
            {
                dq.pop_back();
            }
            dq.push_back(r);

            if(l>dq[0]) dq.pop_front();
            
            if(r+1>=k) 
            {
                ans.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return ans;
    }
};