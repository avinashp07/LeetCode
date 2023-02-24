class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> frontSum(k+1);
        vector<int> rearSum(k+1);
        frontSum[0]=0;
        rearSum[0]=0;
        for(int i=0;i<k;i++)
        {
            frontSum[i+1]=frontSum[i]+cardPoints[i];
            rearSum[i+1]=rearSum[i]+cardPoints[n-1-i];
        }
        int maxSum=0;
        for(int i=0;i<=k;i++)
        {
            int currentSum=frontSum[i]+rearSum[k-i];
            maxSum=max(currentSum,maxSum);
        }
        return maxSum;
    }
};