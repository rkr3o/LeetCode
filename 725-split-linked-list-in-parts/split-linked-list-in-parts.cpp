class Solution {
public:
    int getSize(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);

        if (head == NULL) return ans;

        int n = getSize(head);

        int partSize = n / k;
        int extraParts = n % k;
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            ans[i] = temp;
            for (int j = 1; j < partSize + (i < extraParts); j++) {
                if (temp == NULL) {
                    //cout << "Error: Reached end of list prematurely in part " << i << endl;
                    return ans; // Return to identify the issue
                }
                temp = temp->next;
            }
            //disconnect the part 
            if (temp != nullptr) {
                ListNode* nextNode = temp->next;
                temp->next = nullptr;
                temp = nextNode;
            }
        }

        return ans;
    }
};
