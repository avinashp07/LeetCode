class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        int ans=0;
        int pos=0;
        for(int i=0;i<n;i++)
        {
            if(satisfaction[i]>0) pos++;
            if(pos>1) break;
            int curr=0;
            int x=1;
            for(int j=i;j<n;j++)
            {
                curr+=satisfaction[j]*x;
                x++;
            }
            if(curr>ans) ans=curr;
        }
        return ans;
    }
};