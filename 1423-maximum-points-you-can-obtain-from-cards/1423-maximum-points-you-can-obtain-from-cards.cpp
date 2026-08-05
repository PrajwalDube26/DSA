class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        // int n=cardPoints.size();
        int left=k-1,right=cardPoints.size()-1;
        int sum=0,ans=0;

        for(int i=0;i<k;i++)
        {
            sum+=cardPoints[i];
        }
        ans=sum;

        for(left=k-1;left>=0;left--)
        {
            sum-=cardPoints[left];
            sum+=cardPoints[right];

            ans=max(ans,sum);

            right--;
        }

        return ans;
    }
};