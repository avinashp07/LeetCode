class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(target<matrix[0][0]) return false;
        int beg=0,end=m-1;
        while(beg<=end)
        {
            int mid=beg+(end-beg)/2;
            if(target==matrix[mid][0]) return true;
            else if(target>matrix[mid][0]) beg=mid+1;
            else end=mid-1;
        }
        int row=end;
        beg=0;
        end=n-1;
        while(beg<=end)
        {
            int midd=beg+(end-beg)/2;
            if(target==matrix[row][midd]) return true;
            else if(target>matrix[row][midd]) beg=midd+1;
            else end=midd-1;
        }
        return false;
    }
};