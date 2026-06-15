class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        delet(head,head);
        return head;
    }

    void delet(ListNode* &head,ListNode* h)
    {
        if(h==nullptr || h->next==nullptr){
           head=head->next;
        }
        else{
            delet(head->next,h->next->next);
        }
    }
};