class Solution {
public:

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int n1=nums1.size();
        int n2=nums2.size();

        vector<int>visited(n2,0);
        vector<int>to_return;

        for(int i=0;i<n1;i++)
        {
            int low=0,high=n2-1;
            int ans=-1;

            while(low <= high)
            {
                int mid = ((high - low)/2)+low;

                if(nums2[mid] == nums1[i])
                {
                    if(visited[mid]==0)
                    {
                        ans=mid;
                        high = mid-1;
                    }
                    else
                    {
                        low = mid+1;
                    }
                }
                else if(nums2[mid] > nums1[i])
                {
                    high = mid-1;
                }
                else if(nums2[mid] < nums1[i])
                {
                    low = mid+1;
                }
            }

            if(ans!=-1)
            {
                visited[ans]=1;
                to_return.push_back(nums2[ans]);
            }
        }

        return to_return;
    }
};