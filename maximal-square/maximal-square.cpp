class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]=='1') 
            {
                dp[i][0]=1;
                ans=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]=='1') 
            {
                dp[0][i]=1;
                ans=1;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j]=1;
                    if(matrix[i-1][j]=='1' && matrix[i][j-1]=='1' && matrix[i-1][j-1]=='1')
                    {
                        int x=min(dp[i-1][j],dp[i][j-1]);
                        if(x>=dp[i-1][j-1])
                        {
                            dp[i][j]=pow(sqrt(dp[i-1][j-1])+1,2);
                        }
                        else
                        {
                            dp[i][j]=pow(sqrt(x)+1,2);
                        }
                    }
                }
                int curr=dp[i][j];
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};