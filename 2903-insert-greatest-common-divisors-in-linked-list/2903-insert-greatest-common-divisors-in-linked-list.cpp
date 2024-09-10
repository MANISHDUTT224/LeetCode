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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        if(head->next==nullptr || head==nullptr){
            return head;
        }
        ListNode *node1=head;
        ListNode *node2=head->next;
        while(node2!=nullptr){
            int gcdvalue=calculategcd(node1->val,node2->val);
            ListNode *gcdnode=new ListNode(gcdvalue);
            node1->next=gcdnode;
            gcdnode->next=node2;
            node1=node2;
            node2=node2->next;
        }
        return head;
    }
    int calculategcd(int a,int b){
      while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
      }
      return a;
    }
};