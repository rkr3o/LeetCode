/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* temp = head;
        while(temp!=NULL)
        {
            Node* node = new Node(temp->val);
            mp[temp]=node;
            temp=temp->next;
        }
        Node* t=head;
        while(t!=NULL)
        {
            Node* node = mp[t];
            if(t->next!=NULL) node->next = mp[t->next];
            else node->next=NULL;

            if(t->random!=NULL)node->random=mp[t->random];
            else node->random=NULL;
            t=t->next;
        }
        return mp[head];
    }
};