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
        ListNode *root = new ListNode();
        int next = 0;
        int unit;
        int number;
        ListNode *prev = new ListNode();
        ListNode *ans = root;
        while(l1 && l2){
            number = l1->val + l2->val + next; 
            unit = (number)%10;
            next = number/10;
            ans->val = unit;
            ans->next = new ListNode();
            prev = ans;
            ans = ans->next;
            // cout<<unit<<"\t";
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            number = l1->val + next; 
            unit = (number)%10;
            next = number/10;
            ans->val = unit;
            ans->next = new ListNode();
            prev = ans;
            ans = ans->next;
            // cout<<unit<<"\t";
            l1 = l1->next;
        }
        while(l2){
            number = l2->val + next; 
            unit = (number)%10;
            next = number/10;
            ans->val = unit;
            ans->next = new ListNode();
            prev = ans;
            ans = ans->next;
            // cout<<unit<<"\t";
            l2 = l2->next;
        }
        if(next==0){
            prev->next = nullptr;
        }
        else{
            ans->val = next;
        }
        return root;
    }
};