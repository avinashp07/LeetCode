class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(s1[i]==s2[j]) dp[i][j]=dp[i+1][j+1]+s1[i]+s2[j];

                else
                {
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++) ans+=s1[i];
        for(int i=0;i<n;i++) ans+=s2[i];
        return ans-dp[0][0];
    }
};