class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m=spells.size();
        int n=potions.size();
        vector<int> ans(m,0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<m;i++)
        {
            int curr=0;
            int beg=0,end=n-1;
            while(beg<=end)
            {
                int mid=beg+(end-beg)/2;
                if((long long)spells[i]*(long long)potions[mid]>=success)
                {
                    end=mid-1;
                    
                }
                else
                {
                    beg=mid+1;
                }
            }
            ans[i]=n-beg;
           
        }
        return ans;
    }
};