class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k) k=k%n;
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        int x=n-k;
        nums.erase(nums.begin(),nums.begin()+x);
        nums.erase(nums.end()-k,nums.end());
    }
};