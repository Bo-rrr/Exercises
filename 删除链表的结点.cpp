class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode preHead(0);
        preHead.next = pHead;
        ListNode *preCurr = &preHead;
        while(preCurr->next != nullptr){
            if(preCurr->next->next != nullptr && preCurr->next->val == preCurr->next->next->val){
                while(preCurr->next->next != nullptr && preCurr->next->val == preCurr->next->next->val){
                    ListNode *temp = preCurr->next;
                    preCurr->next = temp->next;
                    delete temp;
                }
                
                ListNode *temp = preCurr->next;
                preCurr->next = temp->next;
                delete temp;
            }else{
                preCurr = preCurr->next;
            }
        }
        
        return preHead.next;
    }
};
