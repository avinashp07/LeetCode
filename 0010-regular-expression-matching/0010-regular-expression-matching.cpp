class Solution {
public:
    bool dfs(int i, int j, string &s, string &p, int m, int n)
    {
        if(i>=m && j>=n) return true;

        if(j>=n) return false;

        bool match = (i<m && (s[i]==p[j] || p[j]=='.'));
        if(j+1<n && p[j+1]=='*') return (match && dfs(i+1,j,s,p,m,n)) || dfs(i,j+2,s,p,m,n);

        if(i<m && (s[i]==p[j] || p[j]=='.')) return dfs(i+1,j+1,s,p,m,n);
        return false;
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        return dfs(0,0,s,p,m,n);
    }
};