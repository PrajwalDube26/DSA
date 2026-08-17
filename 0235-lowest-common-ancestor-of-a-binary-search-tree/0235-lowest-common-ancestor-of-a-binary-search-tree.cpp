/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp=root;
        int pval=p->val,qval=q->val;
        // while(1)
        // {
        //     int tempval=temp->val;
        //     if((tempval > pval && tempval < qval) || (tempval < pval && tempval > qval))
        //     {
        //         return temp;
        //     }
        //     else if(tempval > pval && tempval > qval)
        //     {
        //         temp=temp->left;
        //     }
        //     else if(tempval < pval && tempval < qval)
        //     {
        //         temp=temp->right;
        //     }

        //     if(tempval==pval || tempval==qval)
        //     {
        //         return temp;
        //     }
        // }

        while(1)
        {
            int tempval=temp->val;
            if(tempval > pval && tempval > qval)
            {
                temp=temp->left;
            }
            else if(tempval < pval && tempval < qval)
            {
                temp=temp->right;
            }
            else
            {
                return temp;
            }
        }

        return nullptr;
    }
};