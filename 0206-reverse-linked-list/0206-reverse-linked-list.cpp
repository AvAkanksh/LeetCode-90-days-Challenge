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
//     Interative Solution
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
//     Recursive Solution
    // ListNode* reverseList(ListNode* head) {
    //     if(head==NULL || head->next == NULL){
    //         return head;
    //     }
    //     ListNode* newHead = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = NULL;
    //     return newHead;
    // }
};