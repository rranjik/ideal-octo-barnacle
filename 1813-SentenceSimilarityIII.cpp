class Solution {
public:
    void wordify(string s, vector<string>& w){
        int last_pos = 0;
        int pos = -1;
        while((pos = s.find(' ', last_pos))!=string::npos){
            auto word = s.substr(last_pos, pos-last_pos);
            last_pos = pos+1;
            w.push_back(word);
        }
        w.push_back(s.substr(last_pos));
        return;
    }
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> a;
        vector<string> b;
        wordify(s1, a);
        wordify(s2, b);
        //for(const auto& w : a) cout<<w<<"|"; cout<<endl;
        //for(const auto& w : b) cout<<w<<"|"; cout<<endl;
        if(a.size()>b.size()) swap(a, b);
        int j = 0;
        bool broke = false;
        int br = 0;
        if(a[0]!=b[0]) {broke = true; br++;}
        for(int i = 0; i<b.size(); i++){
            //cout<<"i = "<<i<<" b[i] = "<<b[i]<<endl;
            //cout<<"j = "<<i<<" a[j] = "<<a[j]<<endl;
            //cout<<"br = "<<br<<endl;
            //cout<<"broke = "<<(broke?"true":"false")<<endl;
            if(b[i]==a[j]) {j++; broke = false;}
            else if(!broke) {br++; broke = true;}
            else broke = true;
            if(j==a.size()&&((i==b.size()-1)||(i==0))) return true;
            else if(j == a.size()) return false;
            if(br>=2) return false;
        }
        return false;
    }
};
