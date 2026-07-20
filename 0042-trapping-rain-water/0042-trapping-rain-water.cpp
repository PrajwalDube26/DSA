class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int lmax=height[0],rmax=height[height.size()-1];
        int ans=0;
        while(left<right)
        {
            if(lmax<=rmax)
            {
                if(lmax-height[left]>0)
                    ans+=lmax-height[left];
                left++;
                lmax=max(lmax,height[left]);
            }
            else
            {
                if(rmax-height[right]>0)
                    ans+=rmax-height[right];
                right--;
                rmax=max(rmax,height[right]);
            }
        }

        return ans;
    }
};