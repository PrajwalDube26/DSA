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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m1;
        queue<pair<TreeNode*,pair<int,int>>>q1;
        q1.push({root,{0,0}});
        q1.push({NULL,{INT_MIN,INT_MIN}});
        vector<vector<int>>ans;
        vector<int>temp;

        while(!q1.empty())
        {
            TreeNode* temp = q1.front().first;
            int vr=q1.front().second.first;
            int hr=q1.front().second.second;
            q1.pop();

            if(temp!=NULL)
            {
                m1[vr][hr].insert(temp->val);
                if(temp->left!=NULL)
                {
                    q1.push({temp->left,{vr-1,hr+1}});
                }
                if(temp->right!=NULL)
                {
                    q1.push({temp->right,{vr+1,hr+1}});
                }
            }
        }

        for(auto i:m1)
        {
            temp.clear();
            for(auto j:m1[i.first])
            {
                for(auto k:m1[i.first][j.first])
                {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};