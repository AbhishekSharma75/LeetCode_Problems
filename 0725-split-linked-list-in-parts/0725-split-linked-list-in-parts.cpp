class Solution {
public:
    int getlength(ListNode* head) {
        int len = 0;
        while(head) {
            head = head -> next;
            len++;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int listlength = getlength(head);
        int partSize = listlength / k;
        int extraNodes = listlength % k;
        vector<ListNode*> ans;
        ListNode* curr = head, *prev = NULL;
        while(head) {
            int eachPartSize = partSize;
            ans.push_back(curr);
            while(eachPartSize > 0) {
                prev = curr;
                curr = curr -> next;
                eachPartSize--;
            }

            if(extraNodes != 0 && curr != NULL) {
                extraNodes--;
                prev = curr;
                curr = curr -> next;
            }

            if(prev != NULL) {
                head = curr;
                prev -> next = NULL;
            }
        }

        while(ans.size() != k) {
            ans.push_back(NULL);
        }
        return ans;
    }
};