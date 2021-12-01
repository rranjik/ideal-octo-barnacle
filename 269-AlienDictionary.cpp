class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, set<char>> adjl;
        map<char, int> indegrees;
        for(const auto& w : words){
            for(int i = 0; i<w.size(); i++){
                indegrees[w[i]] = 0;
            }
        }
        for(int i = 0; i<words.size()-1; i++){
            int len = min(words[i].length(), words[i+1].length());
            for(int j = 0; j<len; j++){
                if(words[i][j]!=words[i+1][j]){
                    if(adjl[words[i][j]].find(words[i+1][j])==adjl[words[i][j]].end()){
                        adjl[words[i][j]].insert(words[i+1][j]);
                        indegrees[words[i+1][j]]++;
                    }
                    break;
                }
            }       
        }
        queue<char> q;
        for(auto it : indegrees) if(!it.second) q.push(it.first);
        string res;
        while(!q.empty()){
            auto c = q.front();
            q.pop();
            res+=c;
            if(adjl.find(c)!=adjl.end()){
                for(auto it : adjl[c]){
                    indegrees[it]--;
                    if(!indegrees[it]) q.push(it);
                }
            }
        }
        if(res.length()!=indegrees.size()) return "";
        return res;
        //while(!q.isEmpty()){
        //    char c=q.remove();
        //    result+=c;
        //    if(map.containsKey(c)){
        //        for(char c2: map.get(c)){
        //            degree.put(c2,degree.get(c2)-1);
        //            if(degree.get(c2)==0) q.add(c2);
        //        }
        //    }
        //}
        //if(result.length()!=degree.size()) return "";
        //return result;
    }
};
