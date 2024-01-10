
class Solution {
public:
    void mapParent(unordered_map<TreeNode*,TreeNode*>&parent ,TreeNode* root,int start,TreeNode* &startNode)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            if(node->val==start){
                startNode = node;
            }
            q.pop();
            if(node->left!=NULL)
            {
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
                parent[node->right]=node;
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode* startNode = NULL;
        mapParent(parent,root,start,startNode);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        q.push(startNode);
        vis[startNode]=true;
        int time = 0 ;
        while(!q.empty())
        {
            int n = q.size();
            bool f = 0 ;
            for(int i = 0 ; i < n ; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL and !vis[node->left])
                {
                    f=1;
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right!=NULL and !vis[node->right])
                {
                    f=1;
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(parent[node] and !vis[parent[node]]){
                    f=1;
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }
            }
            if(f)
                time++;
        }
        return time;
    }
};