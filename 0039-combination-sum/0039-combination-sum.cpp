class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int>& candidates,int target,int i,vector<int>& temp,int n)
    {
        if(i>=n || target==0)
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        while(candidates[i]>target)
        {
            i++;
            if(i>=n) return;
        }
        temp.push_back(candidates[i]);
        backtrack(ans,candidates,target-candidates[i],i,temp,n);
        temp.pop_back();
        backtrack(ans,candidates,target,i+1,temp,n);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        backtrack(ans,candidates,target,0,temp,n);
        return ans;
    }
};