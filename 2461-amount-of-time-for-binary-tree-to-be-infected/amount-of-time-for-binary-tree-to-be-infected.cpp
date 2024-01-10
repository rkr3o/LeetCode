
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
        queue<pair<TreeNode*,int>>q;
        unordered_map<TreeNode*,bool>vis;
        q.push({startNode,0});
        vis[startNode]=true;
        int time = 0 ;
        while(!q.empty())
        { 
            TreeNode* node = q.front().first;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            if(node->left!=NULL and !vis[node->left])
            {
                q.push({node->left,t+1});
                vis[node->left]=true;
            }
            if(node->right!=NULL and !vis[node->right])
            {
                q.push({node->right,t+1});
                vis[node->right]=true;
            }
            if(parent[node] and !vis[parent[node]]){
                q.push({parent[node],t+1});
                vis[parent[node]]=true;
            }
        }
        return time;
    }
};