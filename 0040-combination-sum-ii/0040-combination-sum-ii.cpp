class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int>& candidates,int i, int target, vector<int>& temp)
    {
        if(target<=0)
        {
            
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        int prev=-1;
        for(int j=i;j<candidates.size();j++)
        {
            if(candidates[j]==prev) continue;
            temp.push_back(candidates[j]);
            backtrack(ans,candidates,j+1,target-candidates[j],temp);
            temp.pop_back();
            prev=candidates[j];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        backtrack(ans,candidates,0,target,temp);
        return ans;
    }
};