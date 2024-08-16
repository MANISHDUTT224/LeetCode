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
    ListNode* oddEvenList(ListNode* head) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        if(head==nullptr){
            return nullptr;
        }
        ListNode *oddptr=head,*evenptr=head->next,*ehead=head->next;
        while(evenptr!=nullptr && evenptr->next!=nullptr){
            oddptr->next=oddptr->next->next;
            oddptr=oddptr->next;
            evenptr->next=evenptr->next->next;

            evenptr=evenptr->next;
        }
        oddptr->next=ehead;
       
        return head;
    }
};