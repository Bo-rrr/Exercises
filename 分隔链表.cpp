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
    ListNode* partition(ListNode* head, int x) {
        if( head == nullptr || head->next==nullptr){
            return head;
        }
        ListNode fakehead1=ListNode();
        ListNode fakehead2=ListNode();
        ListNode* ip1=&fakehead1;
        ListNode* ip2=&fakehead2;

        for(ListNode *it=head; it!=nullptr;it=it->next ){
            if( it->val < x ){
                ip1->next = it;
                ip1 = it;
            }
            else{
                ip2->next = it;
                ip2 = it;
            }
        }
        ip1->next = fakehead2.next;
        ip2->next = nullptr;
        return fakehead1.next;
    }
};
