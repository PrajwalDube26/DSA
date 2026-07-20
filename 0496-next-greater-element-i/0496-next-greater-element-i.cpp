class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>um;
        for(int i=0;i<nums2.size();i++)
        {
            um[nums2[i]]=i;
        }

        vector<int>ans(nums1.size(),-1);

        for(int i=0;i<nums1.size();i++)
        {
            auto it  = um.find(nums1[i]);

            if(it != um.end())
            {
                int j = it->second;
                int a= nums2[j];

                for(int k=j+1;k<nums2.size();k++)
                {
                    if(nums2[k]>a)
                    {
                        ans[i]=nums2[k];
                        break;
                    }
                }
            }
        }

        return ans;

    }
};