class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>ballmap,colormap;
        vector<int>result(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            int ball=queries[i][0],color=queries[i][1];
            if(ballmap.find(ball)!=ballmap.end()){
                int prevcolor=ballmap[ball];
                colormap[prevcolor]--;
                if(colormap[prevcolor]==0){
                    colormap.erase(prevcolor);
                }
            }
            ballmap[ball]=color;
            colormap[color]++;
            result[i]=colormap.size();
        }
        return result;

    }
};