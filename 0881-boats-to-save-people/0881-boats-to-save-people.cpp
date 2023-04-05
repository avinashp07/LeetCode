class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end(),greater<int>());
        int n=people.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<=j)
        {
            if(people[i]==limit)
            {
                i++;
                ans++;
            }
            else
            {
                if(people[i]+people[j]<=limit)
                {
                    i++;
                    j--;
                    ans++;
                }
                else
                {
                    i++;
                    ans++;
                }
            }
        }
        return ans;
    }
};