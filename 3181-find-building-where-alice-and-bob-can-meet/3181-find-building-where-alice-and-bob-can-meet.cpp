class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<vector<vector<int>>> storequeries(heights.size());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>maxindex;
        vector<int>result(queries.size(),-1);
        for(int curquery=0;curquery<queries.size();curquery++){
            int a=queries[curquery][0],b=queries[curquery][1];
            if(a<b && heights[a]<heights[b]){
                result[curquery]=b;
            }
            else if(a>b && heights[a]>heights[b]){
                result[curquery]=a;
            }
            else if(a==b){
                result[curquery]=a;
            }
            else{
                storequeries[max(a,b)].push_back({max(heights[a],heights[b]),curquery});
            }

        }
        for(int i=0;i<heights.size();i++){
            while(!maxindex.empty()  && maxindex.top()[0]<heights[i]){
               result[maxindex.top()[1]]=i;
                maxindex.pop();
            }
            
            for(auto it:storequeries[i]){
                maxindex.push(it);
            }
        }
        return result;

    }
};