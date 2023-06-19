class Node
{
    public:
    int key,val;
    Node *left;
    Node* right;
    Node(int x, int y)
    {
        key = x;
        val = y;
        left = right = NULL;
    }
};
class LRUCache
{
    public:
   //initial requirement
    int cap ;
    unordered_map<int,Node*>mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    //considering dummy node : these two dont contribute so : key=val=-1;
    LRUCache(int capacity) 
    {
        cap = capacity;
        head->right = tail;
        tail->left = head;
    }
    void addnode(Node* node)
    {
         Node* temp = head->right;
         node->right=temp;
         node->left=head;
         head->right=node;
         temp->left=node;
    }
    void deletenode(Node* node)
    {
         Node* leftNode = node->left;
         Node* rightNode = node->right;
         leftNode->right = rightNode;
         rightNode->left = leftNode;
    }
    int get(int key) 
    {
        //first check for existance of key in map
        if(mp.find(key)!=mp.end())
        {
            Node* resNode = mp[key];
            int resResult = resNode->val;
            mp.erase(key);
            deletenode(resNode);
            addnode(resNode);
            mp[key]=head->right;
            return resResult;
        }

        return -1;
    }
    void put(int key, int value) 
    {
         //for updatin values;
         if(mp.find(key)!=mp.end())
         {
             Node* existAdd = mp[key];
             mp.erase(key);
             deletenode(existAdd);
         }

         if(mp.size()==cap)
         {
             mp.erase(tail->left->key);
             deletenode(tail->left);
         }

         addnode(new Node(key , value));
         mp[key] = head->right;
    }
};

    /**
     *Your LRUCache object will be instantiated and called as such:
     *LRUCache* obj = new LRUCache(capacity);
     *int param_1 = obj->get(key);
     *obj->put(key,value);
     */