class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p1=nums.size()-1,count=0,m=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                count++;
            }
            else if(nums[i]==val)
            {
                while(nums[p1]==val)
                {
                    if(p1==0)
                    {
                        m=1;
                        break;
                    }
                    p1--;
                }
                if(m==0)
                {
                    nums[i]=nums[p1];
                    if(p1!=0)
                    {
                        p1--;   
                    }
                }

            }
        }

        return count;
    }
};