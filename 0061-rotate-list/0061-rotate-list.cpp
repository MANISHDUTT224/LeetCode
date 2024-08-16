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
    ListNode* rotateRight(ListNode* head, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
       if(head==nullptr){
        return head;
       }
       ListNode *curr=head;
       int n=1;
       while(curr->next!=nullptr){
        n++;
        curr=curr->next;
       }
       k%=n;
       curr->next=head;
       curr=head;
       for(int i=1;i<n-k;i++){
        curr=curr->next;
       }
       head=curr->next;
       curr->next=nullptr;
       return head;
    }
};
