class Solution {
public:
    vector<char> getNext(char c){
        if(c=='A') return {'C', 'G', 'T'};
        if(c=='C') return {'A', 'G', 'T'};
        if(c=='G') return {'C', 'A', 'T'};
        if(c=='T') return {'C', 'G', 'A'};
        return {};
    }
    int minMutation(string sg, string eg, vector<string>& bank) {
        //perform a level order BFS starting from sg
        //Changing one char at a time (for all available options)
        //return immedieatey of endGene is found
        unordered_set<string> s;
        s.insert(sg);
        queue<string> q;
        q.push(sg);
        int level = 0;
        unordered_set<string> b{bank.begin(), bank.end()};
        while(!q.empty()){
            int sz = q.size();
            for(int j = 0; j<sz; j++){
                auto f = q.front(); q.pop();
                if(f==eg) return level;
                for(int i = 0; i<f.size(); i++){
                    for(const auto& c : getNext(f[i])){
                        auto fc = f;
                        fc[i] = c;
                        if(b.find(fc)!=b.end()&&s.find(fc)==s.end()){
                            cout<<"adding "<<fc<<endl;
                            q.push(fc);
                            s.insert(fc);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
