class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        map<string, vector<vector<string>>> lw;
        map<string, vector<vector<string>>> fw;
        for(auto p : phrases){
            int last_pos = 0;
            int pos = 0;
            vector<string> words;
            while((pos = p.find(' ', last_pos))!=string::npos){
                string word = p.substr(last_pos, pos-last_pos);
                //cout<<word<<endl;
                words.push_back(word);
                last_pos = pos+1;
            }
            string lastword = p.substr(last_pos, string::npos);
            //cout<<lastword<<endl;
            words.push_back(lastword);
            auto fwiw = words[0];
            auto lwiw = words[words.size()-1];
            lw[lwiw].insert(
                upper_bound(begin(lw[lwiw]), end(lw[lwiw]), words),
            words);
            //lw.insert({words[words.size()-1], words});
            fwiw = words[0];
            fw[fwiw].insert(
                upper_bound(begin(fw[fwiw]), end(fw[fwiw]), words),
            words);
            //fw.insert({words[0], words});
        }
        //for(auto it : lw){
        //    cout<<it.first<<": ";
        //    for(const auto p : it.second){
        //        cout<<"* ";
        //        for(const auto w : p){
        //            cout<<w<<" ";
        //        }
        //    }
        //    cout<<endl;
        //}
        for(auto it : fw){
            cout<<it.first<<": ";
            for(const auto p : it.second){
                cout<<"* ";
                for(const auto w : p){
                    cout<<w<<" ";
                }
            }
            cout<<endl;
        }
        set<string> res;
        for(auto it: fw){
            for(const auto p : it.second){
                if(p[0]!=p[p.size()-1]){
                    if(fw.find(p[p.size()-1])!=fw.end()){
                        for(const auto mp : fw[p[p.size()-1]]){
                            string r;
                            for(int i = 0; i<p.size(); i++){
                                r+=p[i];
                                r+=' ';
                            }
                            for(int i = 1;i<mp.size(); i++){
                                r+=mp[i];
                                r+=' ';
                            }
                            r.pop_back();
                            res.insert(r);
                        }
                    }
                }else{
                    for(int i = 0; i<fw[p[0]].size(); i++){
                        for(int j = 0; j<fw[p[0]].size(); j++){
                            if(j!=i&&fw[p[0]][j][0]==fw[p[0]][i][fw[p[0]][i].size()-1]){
                            string r;
                            for(int k = 0; k<fw[p[0]][i].size(); k++){
                                r+=fw[p[0]][i][k];
                                r+=' ';
                            }
                            for(int k = 1;k<fw[p[0]][j].size(); k++){
                                r+=fw[p[0]][j][k];
                                r+=' ';
                            }
                            r.pop_back();
                            res.insert(r);
                            }
                        }
                    }
                }
            }
        }
        vector<string> rres;
        for(const auto& p : res){
            rres.push_back(p);
        }
        return rres;
    }
};
