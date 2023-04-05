class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans=nums[0],prefixSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefixSum+=nums[i];
            ans=max(ans,(long long)ceil((double)(prefixSum)/(i+1)));
        }
        return ans;
    }
};