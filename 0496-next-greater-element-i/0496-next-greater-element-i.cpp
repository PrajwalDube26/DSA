class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>v1;

        for(int i=0;i<nums1.size();i++)
        {
            int a;
            bool m=0;
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    for(int k=j+1;k<nums2.size();k++)
                    {
                        if(nums2[k]>nums1[i])
                        {
                            m=1;
                            a=nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
            if(!m)
            {
                a=-1;
            }

            v1.push_back(a);
        }

        return v1;
        
    }
};