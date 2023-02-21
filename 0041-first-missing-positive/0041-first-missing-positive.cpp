class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0) nums[i]=0;
        }
        for(int i=0;i<n;i++)
        {
           if(abs(nums[i])<=n && abs(nums[i])>0)
           {
               if(nums[abs(nums[i])-1] > 0)
               {
                   nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1]*(-1);
               }
               if(nums[abs(nums[i])-1] == 0)
               {
                   nums[abs(nums[i]) - 1] = (n+1)*(-1);
               }
           }
        }
        for(auto x:nums)
        {
            cout<<x<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            if(nums[i-1]>=0) return i;
        }
        return n+1;
    }
};