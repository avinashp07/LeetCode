class Solution {
public:
    int maxVowels(string s, int k) {
        string v="aeiou";
        int ans=0;
        int curr=0;
        for(int i=0;i<k;i++)
        {
            if(v.find(s[i])!=string::npos) curr++;
        }
        int i=0,j=k-1;
        ans=max(ans,curr);
        while(i<=s.size()-k)
        {
            if(v.find(s[i])!=string::npos) curr--;
            if(v.find(s[i+k])!=string::npos) curr++;
            i++;
            j++;
            ans=max(ans,curr);
        }
        return ans;
    }
};