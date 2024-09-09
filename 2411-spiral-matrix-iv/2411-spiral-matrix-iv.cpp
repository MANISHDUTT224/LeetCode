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
    int getValue(ListNode* &head){
        int val=-1;
        if(head){
            val=head->val;
            head=head->next;
        }
        return val;
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int rs=0,cs=0,re=m-1,ce=n-1;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        while(head && rs<=re && cs<=ce){
        for(int i=cs;i<=ce;i++){
            ans[rs][i]=getValue(head);
        }
        rs++;
        for(int i=rs;i<=re;i++){
            ans[i][ce]=getValue(head);
        }
        ce--;
        if(re>=rs){
            for(int i=ce;i>=cs;i--){
                ans[re][i]=getValue(head);
            }
            re--;
        }
        if(ce>=cs){
            for(int i=re;i>=rs;i--){
                ans[i][cs]=getValue(head);
            }
            cs++;
        }
        }
        return ans;

    }
};