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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *pre=dummy;
        for(int i=0;i<left-1;++i){
            pre=pre->next;
        }
        ListNode *rightNode=pre;
        for(int i=0;i<right-left+1;++i){
            rightNode=rightNode->next;
        }
        ListNode *leftNode=pre->next;
        ListNode *curr=rightNode->next;

        pre->next=nullptr;
        rightNode->next=nullptr;

        reverseLinkList(leftNode);
        pre->next=rightNode;
        leftNode->next=curr;
        return dummy->next;
    }
private:
    void reverseLinkList(ListNode *head){
        ListNode *pPre=nullptr;
        ListNode *pCur=head;

        while(pCur!=nullptr){
            ListNode *pNext=pCur->next;
            pCur->next=pPre;
            pPre=pCur;
            pCur=pNext;
        }
    }
};
