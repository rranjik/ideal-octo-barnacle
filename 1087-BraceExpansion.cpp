class Solution {
public:
    void dfs(int i, vector<string>& res, string c, 
             const vector<pair<string, bool>>& adjl){
        if(i>=adjl.size()){
            res.push_back(c);
            return;
        }
        if(adjl[i].second){
            for(int j = 0; j<adjl[i].first.length(); j++){
                c+=adjl[i].first[j];
                dfs(i+1, res, c, adjl);
                c.pop_back();
            }
        }else{
            c+=adjl[i].first;
            dfs(i+1, res, c, adjl);
        }
    }
    vector<string> expand(string s) {
        vector<pair<string, bool>> adjl;
        string c = s;
        int last_pos = 0;
        int pos_of_open = 0;
        while((pos_of_open = c.find('{', last_pos))!=string::npos){
            string nochoice = c.substr(last_pos, pos_of_open-last_pos);
            if(nochoice.length()>0) {
                adjl.push_back(make_pair(nochoice, false));
            }
            cout<<"no choice "<< nochoice <<endl;
            auto pos_of_close = c.find('}', pos_of_open);
            string within = c.substr(pos_of_open+1, pos_of_close-pos_of_open-1);
            within.erase(remove(within.begin(), within.end(), ','), within.end());
            sort(within.begin(), within.end());
            if(within.length()>0)
                adjl.push_back(make_pair(within, true));
            cout<<"within "<<within <<endl;
            last_pos = pos_of_close +1;
        }
        string lastnochoice = c.substr(last_pos, string::npos);
        cout<<"last no choice "<<lastnochoice<<endl;
        if(lastnochoice.length()>0) {
            adjl.push_back(make_pair(lastnochoice, false));
        }
        for(const auto& c : adjl){
            cout<<c.first<<" "<<(c.second?"true":"false")<<endl;
        }
        
        vector<string> res;
        string start;
        dfs(0, res, start, adjl);
        return res;
    }
};
