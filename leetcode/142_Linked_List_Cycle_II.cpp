// 这题的思路比较巧妙，考察的还是快慢指针，但是要考虑环出现的位置。
// 最重要的一点是快指针的速度是慢指针的两倍，而且快指针要移动多一圈才可以追上慢指针。
// 这样一来就可以计算出快指针离环的入口的距离和链表起点到环入口的距离相等

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                break;
            }
        }
        if(!fast || !fast->next){
            return NULL;
        }
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};