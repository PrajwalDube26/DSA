class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int n=students.size();
        vector<int>visited(n,0);
        int j=0,i=0;
        int count=0;
        
        while(j<n)
        {
            if(!visited[i])
            {
                if(sandwiches[j]==students[i])
                {
                    visited[i]=1;
                    j++;
                    count=0;
                }
            }
            count++;
            if(count==n)
            {
                return n-j;
            }
            i=(i+1)%n;
        }

        return n-j;
        
    }
};