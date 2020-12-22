/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead || k<= 0)return nullptr;
        ListNode* prev = pListHead,*cur = pListHead;
        while(k--){
            if(cur)cur = cur->next;
            else return nullptr;
        }
        while(cur){
            cur = cur->next;
            prev = prev->next;
        }
        return prev;
    }
};