/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        ListNode* fast=pHead;
        ListNode* low=pHead;
        while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
        {
            fast=fast->next->next;
            low=low->next;
            if(fast==low)
                break;
        }
        if(fast==NULL||fast->next==NULL||fast->next->next==NULL)
            return NULL;
        low=pHead;
        while(low!=fast)
        {
            low=low->next;
            fast=fast->next;
        }
        return low;
            

    }
};