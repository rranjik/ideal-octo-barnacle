class WordDistance {
public:
    unordered_map<string, vector<int>> m;
    WordDistance(vector<string>& words) {
        for(int i = 0; i<words.size(); i++){
            if(m.find(words[i])!=m.end()){
                m[words[i]].push_back(i);
            }else {
                m[words[i]]=vector<int>();
                m[words[i]].push_back(i);
            }
        }
    }
    
    int shortest(string word1, string word2) {
        //cout<<"m["<<word1<<"]= "<<m[word1]<<"; m["<<word2<<"]= "<<m[word2]<<endl;
        int res = numeric_limits<int>::max();
        for(int i = 0; i<m[word1].size(); i++){
            for(int j = 0; j<m[word2].size(); j++){
                res = min(res, abs(m[word1][i]-m[word2][j]));
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
