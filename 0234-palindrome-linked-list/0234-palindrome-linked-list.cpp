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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *cur=slow,*prev=nullptr,*next=slow;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        ListNode *firsthalf=head,*sechead=prev;
        while(sechead!=nullptr){
            if(firsthalf->val!=sechead->val){
                return false;
            }
            firsthalf=firsthalf->next;
            sechead=sechead->next;
        }
        return true;
    }
};