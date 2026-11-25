
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* cur=head;
            ListNode dummy(0, head);
            ListNode* prevTail=&dummy;//已完成反转的部分（上一组）的尾部
            while (cur != nullptr) {
                ListNode* kstart = cur;//记录当前组开头
                for (int i = 0; i < k-1; ++i) {
                    cur = cur->next;//cur往后找当前组结尾
                    if (cur == nullptr && i < k) {//如果最后一组不满k个
                        prevTail->next=kstart;//不逆转直接接在尾部
                        return dummy.next;
                    }
                }
                ListNode* kend = cur->next;//记录下一组的开头
                cur->next = nullptr;//断链以便逆转当前组
                ListNode* newStart = reverseLinklist(kstart);
                prevTail->next=newStart;//接上前一组
                prevTail=kstart;//更新尾部
                cur = kend;//cur走到下一组开头
            }
            return dummy.next;
        }

    private:
        ListNode* reverseLinklist(ListNode* head) {
            ListNode* pre = nullptr;
            ListNode* cur = head;
            if (head == nullptr) {
                return head;
            }
            while (cur) {
                ListNode* pNext = cur->next;
                cur->next = pre;
                pre = cur;
                cur = pNext;
            }
            return pre;
        }
};
