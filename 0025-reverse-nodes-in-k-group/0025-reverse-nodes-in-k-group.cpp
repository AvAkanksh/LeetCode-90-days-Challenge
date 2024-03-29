class Solution {
public:
    
    bool length(ListNode* head, int k){
        while(k && head){
            head= head->next;
            k--;
        }
        return k==0;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){return head;}
        if(!length(head,k)){return head;}
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex  = NULL;
        ListNode* start = head;
        for(int i = 0 ; i<k ; i++){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        
        head = prev;
        start->next = reverseKGroup(nex,k);
        return head;
        
    }

};