class Solution {
public:

    int is_possible(int num,vector<int> &position, int m)
    {
        int count=m;
        int n=position.size();
        int ans=INT_MAX;
        int curr=position[0];
        int find=position[0]+num;
        count--;
        
        for(int i=1;i<n;i++)
        {
            if(position[i]>=find)
            {
                ans = min(ans,position[i]-curr);
                count--;
                curr=position[i];
                find=position[i]+num;
            }
            
            if(count==0)
            {
                return ans;
            }
        }
        if(count==0)
        {
            return ans;
        }
        
        return -1;
    }

    
    int maxDistance(vector<int>& position, int m) 
    {
        sort(position.begin(),position.end());
        
        int n=position.size();
        int low=1;
        int high=position[n-1]-position[0];
        int mid;
        int ans = INT_MIN;
        
        while(low<=high)
        {
            mid = ((high-low)/2) + low;
            int z = is_possible(mid,position,m);
            
            if(z==-1)
            {
                high = mid-1;
            }
            else
            {
                ans = max(ans,z);
                low = mid+1;
            }
        }
        
        return ans;
        
    }
};