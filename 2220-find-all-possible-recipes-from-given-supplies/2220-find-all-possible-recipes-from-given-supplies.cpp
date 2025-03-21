class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>availsupplies;
        unordered_map<string,int>recipetoi;
        unordered_map<string,vector<string>>dependency;
        for(string supply:supplies){
            availsupplies.insert(supply);
        }
        for(int i=0;i<recipes.size();i++){
            recipetoi[recipes[i]]=i;
        }
        vector<int>indegree(recipes.size(),0);
        for(int i=0;i<recipes.size();i++){
            for(string ingredient:ingredients[i]){
                if(!availsupplies.count(ingredient)){
                dependency[ingredient].push_back(recipes[i]);
                indegree[i]++;
                }
            }
        }
        queue<int>q;
        for(int i=0;i<recipes.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<string>createdrecipes;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            string r=recipes[i];
            createdrecipes.push_back(r);
            if(!dependency.count(r)){
                continue;
            }
            for(string d:dependency[r]){
                if(--indegree[recipetoi[d]]==0){
                    q.push(recipetoi[d]);
                }
            }
        }
        return createdrecipes;
    }
};