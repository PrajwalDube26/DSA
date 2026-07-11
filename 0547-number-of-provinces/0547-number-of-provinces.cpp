class Solution {
public:
    void bfs(int source,vector<vector<int>>& v1, vector<int>& visited)
    {
        queue<int>q1;
        q1.push(source);

        visited[source]=1;

        while(!q1.empty())
        {
            int a=q1.front();

            for(int i=0;i<v1[a].size();i++)
            {
                if(visited[v1[a][i]]==0)
                {
                    visited[v1[a][i]]=1;
                    q1.push(v1[a][i]);
                }
            }

            q1.pop();
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        vector<vector<int>>v1(isConnected.size());

        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    v1[i].push_back(j);
                }
            }
        }

        vector<int>visited(isConnected.size(),0);
        int count=0;

        for(int i=0;i<isConnected.size();i++)
        {
            if(visited[i]==0)
            {
                bfs(i,v1,visited);
                count++;
            }
        }
        
        return count;
        
    }
};