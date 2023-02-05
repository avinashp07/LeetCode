class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        bool rev=false;
        if(nums.size()==1) return;
        if(nums.size()==2) 
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i])
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(nums[j]>nums[i])
                    {
                        int temp=nums[j];
                        nums[j]=nums[i];
                        nums[i]=temp;
                        break;
                    }
                }
                reverse(nums.begin()+i+1,nums.end());
                rev=true;
                break;
            }
        }
        if(!rev) sort(nums.begin(),nums.end());
    }
};