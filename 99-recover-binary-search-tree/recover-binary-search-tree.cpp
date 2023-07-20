 
class Solution {
public:
    TreeNode* prev ;
    TreeNode* first = NULL;
    TreeNode* mid = NULL; 
    TreeNode* last = NULL;
    void solve(TreeNode* root)
    {
        if(root==NULL)return;
        solve(root->left);
        if(prev!=NULL and root->val < prev->val)
        {
            if(first == NULL)
            {
                 first = prev;
                 mid = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=last=mid=NULL;
        prev = new TreeNode(INT_MIN);
        solve(root);

        if(first and last)swap(first->val ,last->val);
        else if(first and mid)swap(first->val,mid->val); 
    }
};