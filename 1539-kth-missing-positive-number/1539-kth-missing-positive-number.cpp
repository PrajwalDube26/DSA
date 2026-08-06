class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n=arr.size();
        int left=0,right=n-1,k1=k;
        int mid,miss_in_left;

        while(right>=left)
        {
            mid = ((right-left)/2) + left;

            miss_in_left = arr[mid] - (mid+1);

            if(miss_in_left==k)
            {
                break;
            }
            else if(miss_in_left>k)
            {
                right = mid-1;
            }
            else if(miss_in_left<k)
            {
                left  = mid+1;
            }
        }

        int ans;

        if(miss_in_left>=k)
        {
            int move_left = miss_in_left -k +1;
            ans = arr[mid];

            for(int i=0;i<move_left ; i++)
            {
                if(mid-1 == -1)
                {
                    return ans - move_left +i;
                }
                else
                {
                    if(arr[mid-1] != ans-1)
                    {
                        ans--;
                    }
                    else
                    {
                        while(arr[mid-1] == ans-1)
                        {
                            mid--;
                            ans--;

                            if(mid-1 == -1)
                            {
                                return ans - move_left +i;
                            }
                        }
                        ans--;
                    }
                }
            }
        }
        else if(miss_in_left < k)
        {
            int move_right = k-miss_in_left;
            ans = arr[mid];

            for(int i=0;i<move_right ; i++)
            {
                if(mid+1 == n)
                {
                    return ans + move_right -i;
                }
                else
                {
                    if(arr[mid+1] != ans+1)
                    {
                        ans++;
                    }
                    else
                    {
                        while(arr[mid+1] == ans+1)
                        {
                            mid++;
                            ans++;

                            if(mid+1 == n)
                            {
                                return ans + move_right -i;
                            }
                        }
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};