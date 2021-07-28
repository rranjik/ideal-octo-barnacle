class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        sort(begin(words), end(words), [](const string& a, const string& b){return a.length()<b.length();});
        vector<bool> c(words.size(), true);
        for(int i = 0; i<words.size()-1; i++){
            for(int j = i+1; c[i]&&j<words.size(); j++){
                cout<<"finding "<<words[i]<<" in "<<words[j];
                if((words[j].find(words[i])!=string::npos)) {
                    cout<<" found!"<<endl;
                    res.push_back(words[i]);
                    c[i] = false;
                    break;
                }
            }
        }
        return res;
    }
};
