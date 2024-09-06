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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        ListNode *prev=head,*cur=head;
        while(cur!=nullptr){
            if(mp[cur->val]>0){
                if(prev==cur){
                    if(head==cur){
                        head=head->next;
                    }
                    cur=cur->next;
                    prev=cur;
                }
                else{
                    cur=cur->next;
                    prev->next=cur;
                }
            }
            else{
                prev=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};