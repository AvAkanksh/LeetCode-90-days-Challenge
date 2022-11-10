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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = head;
        ListNode *prev = NULL;
        ListNode *curr = slow;
        while(curr){
            ListNode *next = curr->next;            
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow = prev;
        while(slow){
            if(fast->val != slow->val){
                return false;
            }
            else{
                cout<<fast->val<<" "<<slow->val<<endl;
                fast = fast->next;
                slow = slow->next;
            }
        }
        return true;
    }
};