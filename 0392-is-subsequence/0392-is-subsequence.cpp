class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int m=s.size();
        int n=t.size();
        while(j<=n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(i<=m) return false;

        else
        return true;
    }
};