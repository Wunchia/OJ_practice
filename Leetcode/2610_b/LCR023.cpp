// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

            if (headA == nullptr || headB == nullptr) return nullptr;

            ListNode *pA = headA;
            ListNode *pB = headB;

            // 只要两个指针不相等，就一直走
            while (pA != pB) {
                // pA 走到头就转到 headB，否则继续走下一步
                pA = (pA == nullptr) ? headB : pA->next;
                // pB 走到头就转到 headA，否则继续走下一步
                pB = (pB == nullptr) ? headA : pB->next;
            }

            // 出来的要么是交点，要么是同时为 nullptr（代表不相交）
            return pA;

        }
};
