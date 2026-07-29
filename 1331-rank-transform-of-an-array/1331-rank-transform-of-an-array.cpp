class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>m1;

        for(int i=0;i<arr.size();i++)
        {
            pq.push(arr[i]);
        }
        int a,b=INT_MAX,i=1;
        while(!pq.empty())
        {
            a=pq.top();
            if(a!=b)
            {
                m1[a]=i;
                i++;
            }
            pq.pop();
            b=a;
        }

        for(int j=0;j<arr.size();j++)
        {
            int z=arr[j];
            if(m1.find(z)!=m1.end())
            {
                arr[j]=m1[z];
            }
        }

        return arr;
    }
};