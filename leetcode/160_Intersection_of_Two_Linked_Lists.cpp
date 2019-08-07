class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA), lenB = getLen(headB);
        if(lenA>lenB){
            for(int i=0; i<lenA-lenB; i++){
                headA = headA->next;
            }
        }
        else{
            for(int i=0; i<lenB-lenA; i++){
                headB = headB->next;
            }
        }
        while(headA&&headB&&headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return (headA==headB) ? headA : NULL;
    }
private:
    int getLen(ListNode *list){
        int cnt = 0;
        ListNode *tmp = list;
        while(tmp){
            tmp = tmp->next;
            ++cnt;
        }
        return cnt;
    }
};