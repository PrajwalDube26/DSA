/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {};
        }
        
        unordered_map<int,int>m1;
        queue<pair<TreeNode*,int>>q1;
        q1.push({root,0});
        vector<int>ans;
        int mx = 0;
        
        while(!q1.empty())
        {
            TreeNode* temp = q1.front().first;
            int hr = q1.front().second;
            q1.pop();
            
            mx = max(mx, hr);
            
            if(m1.find(hr)==m1.end())
            {
                m1[hr]=temp->val;
            }

            if(temp->right!=NULL)
            {
                q1.push({temp->right,hr+1});
            }

            if(temp->left!=NULL)
            {
                q1.push({temp->left,hr+1});
            }
            
        }
        
        for(int i=0;i<=mx;i++)
        {
            ans.push_back(m1[i]);
        }
        
        return ans;
        
    }
};