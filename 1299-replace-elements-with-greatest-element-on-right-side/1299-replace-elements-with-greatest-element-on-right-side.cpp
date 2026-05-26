class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxa=-1;

        for(int i=arr.size()-1;i>=0;i--)
        {
            int temp=maxa;
            maxa=max(maxa,arr[i]);

            arr[i]=temp;
        }

        return arr;
    }
};