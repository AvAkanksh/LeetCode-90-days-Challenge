/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;
        int val;
        ListNode *root = new ListNode();
        ListNode *ans = root;
        while(l1 || l2 || carry){
            int l1Value = l1 ? l1->val : 0;
            int l2Value = l2 ? l2->val : 0;
            val = l1Value + l2Value + carry;
            carry = val/10;
            val = val%10;
            ans->next = new ListNode(val);
            ans = ans->next;
            l1 = (l1&&l1->next) ? l1->next : nullptr;
            l2 = (l2&&l2->next) ? l2->next : nullptr;
        }
        return root->next;
    }
};