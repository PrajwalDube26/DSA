class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int>s1;
        int i=0,j=0,z=0;

        for(int i=0;i<m;i++)
        {
            s1.push_back(nums1[i]);
        }
        while(i<m && j<n)
        {
            if(s1[i]<nums2[j])
            {
                nums1[z]=s1[i];
                z++;
                i++;
            }
            else
            {
                nums1[z]=nums2[j];
                z++;
                j++;
            }
        }
        while(i<m)
        {
            nums1[z]=s1[i];
            z++;
            i++;
        } 
        while(j<n)
        {
            nums1[z]=nums2[j];
            z++;
            j++;
        }
        
    }
};