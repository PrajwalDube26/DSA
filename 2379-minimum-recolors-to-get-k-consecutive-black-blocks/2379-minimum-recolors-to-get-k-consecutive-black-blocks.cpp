class Solution {
public:
    //fix sized sliding window
    int minimumRecolors(string blocks, int k) {
        int wcount=0,ans=INT_MAX;
        int n=blocks.length();

        for(int i=0;i<k;i++)
        {
            if(blocks[i]=='W')wcount++;
        }

        ans=min(ans,wcount);

        int left=0,right=k;

        for(right=k;right<n;right++)
        {
            if(blocks[left]=='W')wcount--;

            left++;

            if(blocks[right]=='W')wcount++;

            ans=min(ans,wcount);
        }

        return ans;
    }
};