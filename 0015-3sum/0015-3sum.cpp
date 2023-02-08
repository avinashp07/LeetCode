class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=i+1,k=n-1;
        while(i<n-2)
        {
            if(i>0 && nums[i]==nums[i-1]) 
            {
                i++;
                continue;
            }
            j=i+1,k=n-1;
            while(j<k)
            {
                int target=nums[i]+nums[j]+nums[k];
                if(target>0)
                {
                    k--;
                }
                else if(target<0)
                {
                    j++;
                }
                else
                {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ans.push_back(v);
                    j++;
                    while(j<k && nums[j-1]==nums[j]) 
                    {
                        j++;
                    }
                }
            }
            i++;
        }
        return ans;
    }
};