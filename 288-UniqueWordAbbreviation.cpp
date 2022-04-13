class ValidWordAbbr {
public:
    unordered_map<string, int> dict;
    unordered_set<string> acdict;
    ValidWordAbbr(vector<string>& dictionary) {
        for(auto w : dictionary){
            acdict.insert(w);
            if(w.length()<=2){
                //dict.insert(w);
                dict[w]++;
            }else{
                string numeronym;
                numeronym+=w[0];
                numeronym+=to_string(w.length()-2);
                numeronym+=w[w.length()-1];
                dict[numeronym]++;
            }
        }
    }
    
    bool isUnique(string w) {
        if(acdict.find(w)==acdict.end()){
            //if not found in the dictionary 
            string numeronym;
            numeronym+=w[0];
            numeronym+=to_string(w.length()-2);
            numeronym+=w[w.length()-1];
            return dict.find(numeronym)==dict.end();
        }else {
            if(w.length()<=2)return true;
            string numeronym;
            numeronym+=w[0];
            numeronym+=to_string(w.length()-2);
            numeronym+=w[w.length()-1];
            return dict[numeronym]==1;
        }
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
