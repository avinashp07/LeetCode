class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]==nums[i+1]) 
            {
                if(count<2) count++;
                else nums.erase(nums.begin()+i);
            }
            else
            count=1;
        }
        return nums.size();
    }
};