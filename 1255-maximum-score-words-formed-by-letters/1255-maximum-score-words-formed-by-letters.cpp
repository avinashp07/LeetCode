class Solution {
public:
    int ans=0;
    int checkScore(string word,vector<int>& score)
    {
        int val=0;
        for(int i=0;i<word.length();i++)
        {
            val+=score[word[i]-'a'];
        }
        return val;
    }
    void backtrack(vector<string>& temp,int i,vector<string>& words, map<char,int> mp,vector<int>& score)
    {
        if(i>=words.size())
        {
            int curr=0;
            for(int j=0;j<temp.size();j++)
            {
                curr+=checkScore(temp[j],score);
            }
            ans=max(curr,ans);
            return;
        }
        map<char,int> mpt=mp;
        bool br=false;
        for(int j=0;j<words[i].size();j++)
        {
            if(mpt.find(words[i][j])!=mpt.end())
            {
                if(mpt[words[i][j]]==1)
                {
                    mpt.erase(mpt.find(words[i][j]));
                }
                else
                {
                    mpt[words[i][j]]--;
                }
            }
            else
            {
                br=true;
                break;
            }
        }
        if(br)
        {
            mpt=mp;
            backtrack(temp,i+1,words,mpt,score);
        }
        else
        {
            temp.push_back(words[i]);
            backtrack(temp,i+1,words,mpt,score);
            temp.pop_back();
            backtrack(temp,i+1,words,mp,score);
        }
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<string> temp;
        map<char,int> mp;
        for(int i=0;i<letters.size();i++)
        {
            if(mp.find(letters[i])!=mp.end())
            {
                mp[letters[i]]++;
            }
            else
            {
                mp[letters[i]]=1;
            }
        }
        backtrack(temp,0,words,mp,score);
        return ans;
    }
};