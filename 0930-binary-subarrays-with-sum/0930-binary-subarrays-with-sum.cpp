class Solution {
public:

    int zerosub(int count)
    {
        int p=count*(count+1);
        return p/2;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int n = nums.size();
        vector<int>prev(n,-1);
        vector<int>next(n,n);
        int p=-1,ne=n;
        int right=0,left=0;
        int count1=0;
        if(goal==0)
        {
            int ans=0,count=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==1)
                {
                    ans+=zerosub(count);
                    count=0;
                }
                else if(nums[i]==0)
                {
                    count++;
                }
            }
            ans+=zerosub(count);

            return ans;
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                prev[i]=p;
                p=i;
                count1++;
            }
        }

        if(count1<goal)return 0;

        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==1)
            {
                next[i]=ne;
                ne=i;
            }
        }

        int count=0;
        for(right=0;right<n;right++)
        {
            if(nums[right]==1)
            {
                if(count<goal)
                {
                    count++;
                    if(count==goal)
                    {
                        break;
                    }
                }
            }
        }

        while(nums[left]!=1)
        {
            left++;
        }

        int ans=0;
        int leftc=left-prev[left];
        int rightc=next[right]-right;
        ans+=leftc*rightc;

        if(next[right]==n)
        {
            return ans;
        }
        while(right<n)
        {
            right++;
            if(right==n)break;
            while(nums[right]!=1)
            {
                right++;
                if(right==n)break;
            }

            left++;
            if(left==n)break;
            while(nums[left]!=1)
            {
                left++;
                if(left==n)break;
            }

            leftc=left-prev[left];
            rightc=next[right]-right;
            ans+=leftc*rightc;

            if(next[right]==n)
            {
                return ans;
            }
        }

        return ans;
    }
};