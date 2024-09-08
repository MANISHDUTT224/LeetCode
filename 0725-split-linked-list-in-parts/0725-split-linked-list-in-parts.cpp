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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<ListNode*>node;
        ListNode *cur=head;
        int n=0;
        node.push_back(cur);
        while(cur){
            cur=cur->next;
            node.push_back(cur);
            n++;
        }
        auto [q,r]=div(n,k);
        vector<int>isLen(k,q);
        fill(isLen.begin(),isLen.begin()+r,q+1);
        vector<ListNode*>ans(k,{});
        int bI=0,eI;
        for(int i=0;i<k;i++){
            bI=(i==0)?0:bI+isLen[i-1];
            eI=(isLen[i]==0)?bI:bI+isLen[i]-1;
            ans[i]=node[bI];
            ListNode *last=node[eI];
            if(last){
                last->next=nullptr;
            }
        }
        return ans;

    }
};