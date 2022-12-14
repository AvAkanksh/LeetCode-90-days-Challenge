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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *root = new ListNode();
        ListNode *ans = root;
        while(list1 && list2){
            if(list1->val < list2->val){
                ans->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{
                ans->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            ans = ans->next;
        }
        if(list1){
            ans->next = list1;
        }
        else{
            ans->next = list2;
        }
        return root->next;
    }
};