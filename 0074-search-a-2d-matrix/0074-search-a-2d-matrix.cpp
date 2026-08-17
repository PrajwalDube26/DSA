class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=n-1;

        while(low<=high)
        {
            int mid = ((high-low)/2) + low;

            if(matrix[mid][0] > target)
            {
                high=mid-1;
            }
            else if(matrix[mid][m-1] < target)
            {
                low = mid+1;
            }
            else
            {
                int low2=0,high2=m-1;

                while(low2<=high2)
                {
                    int mid2= ((high2-low2)/2) + low2;

                    if(matrix[mid][mid2]==target)
                    {
                        return true;
                    }
                    else if(matrix[mid][mid2] > target)
                    {
                        high2 = mid2-1;
                    }
                    else if(matrix[mid][mid2] < target)
                    {
                        low2 = mid2 +1;
                    }
                }

                return false;
            }
        }
        return 0;
        
    }
};