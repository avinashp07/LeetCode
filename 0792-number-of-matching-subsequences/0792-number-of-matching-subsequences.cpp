class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> v(26);
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a'].push_back(i);
        }
        int res=0;
        for(int i=0;i<words.size();i++)
        {
            int prev=0;
            bool Found=true;
            for(int j=0;j<words[i].size();j++)
            {
                auto it=lower_bound(v[words[i][j]-'a'].begin(),v[words[i][j]-'a'].end(),prev);
                if(it==v[words[i][j]-'a'].end())             
                {
                    Found=false;
                    break;
                }
                else
                {
                   prev=*it+1;
                }
            }
            if(Found) res++;
        }
        return res;
    }
};