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
        string num = "";
        string rnum;
        while(head!=NULL){
            num+=to_string(head->val);
            head = head->next;
        }
        rnum = num;
        reverse(rnum.begin(), rnum.end());
        return num==rnum;
    }
};