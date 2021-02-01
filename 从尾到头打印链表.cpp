class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.insert(arr.begin(),head->val);
            head = head->next;
        }
        return arr;
    }
};
