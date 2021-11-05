class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        //company occurances
        unordered_map<string, set<int>> cmpocc;
        //favoriteCompanies indexes zipped
        vector<pair<int, vector<string>>> fci;
        for(int i = 0; i<favoriteCompanies.size(); i++){
            fci.push_back({i, favoriteCompanies[i]});
        }
        sort(fci.begin(), fci.end(), 
             [](const pair<int, vector<string>>& a, const pair<int, vector<string>>& b){return a.second.size()>b.second.size();});
        vector<int> res;
        for(const auto& fc : fci){
            vector<int> inter(favoriteCompanies.size());
            iota(inter.begin(), inter.end(), 0);
            //cout<<"person "<<fc.first<<" ";
            //for(const auto& c : fc.second) cout<<c<<" "; cout<<endl;
            //cout<<"after iota "<<" ";
            //for(const auto& p : inter) cout<<p<<" "; cout<<endl;
            for(const auto& c : fc.second){
                vector<int> occiof;
                if(cmpocc.find(c)!=cmpocc.end()){
                    vector<int> occioft(cmpocc[c].begin(), cmpocc[c].end());
                    
                    //cout<<" "<<c<<" was found in person(s): ";
                    //for(const auto& occ : occiof) cout<<occ<<" "; cout<<endl;
                    
                    //occurances in other favorites
                    occiof = occioft;
                }
                vector<int> tempinter;
                set_intersection(inter.begin(), inter.end(),
                          occiof.begin(), occiof.end(),
                          back_inserter(tempinter));
                inter = tempinter;
                
                //cout<<" after intersection ";
                //for(const auto& i : inter) cout<<i<<" "; cout<<endl;
                
                cmpocc[c].insert(fc.first);
            }
            if(!inter.size()) res.push_back(fc.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
