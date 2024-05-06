/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<int> s;
        ListNode* cur = head;
        
        while (cur) {
            while (!s.empty() && cur->val > s.top()) {
                s.pop();
            }
            s.push(cur->val);
            cur = cur->next;
        }
        
        ListNode* dummy = new ListNode();
        cur = dummy;
        while (!s.empty()) {
            cur->next = new ListNode(s.top());
            cur = cur->next;
            s.pop();
        }
        
        return dummy->next;
    }
};
