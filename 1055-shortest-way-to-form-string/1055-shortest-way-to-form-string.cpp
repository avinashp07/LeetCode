class Solution {
public:
    int shortestWay(string source, string target) {
        int i=0,j=0;
        int ans=0;
        int m=source.length();
        int n=target.length();
        while(j!=n)
        {
            if(i==0) ans++;
            if(source.find(target[j])==-1)
            {
                return -1;
            }
            if(source[i]==target[j])
            {
                i++;
                i=i%m;
                j++;
            }
            else
            {
                i++;
                i=i%m;
            }
        }
        return ans;
    }
};