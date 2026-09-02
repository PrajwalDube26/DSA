/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) 
    {
        int low=1,high=n;
        int ans;

        while(low<=high)
        {
            int mid = ((high-low)/2) + low;

            int isvalid = guess(mid);

            if(isvalid == 0)
            {
                return mid;
            }
            else if(isvalid == 1)
            {
                low=mid+1;
            }
            else if(isvalid == -1)
            {
                high = mid - 1;
            }
        }

        return -1;
        
    }
};