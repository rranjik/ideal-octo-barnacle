class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> res;
        string s;
        int nz=0;
        for(int i = 0; i<word.size(); i++){
            if(word[i]>='0'&&word[i]<='9'){
                if(s.size()==0&&word[i]=='0'){
                    nz++;
                }else{
                    nz=0;
                    s+=string(1, word[i]);
                }
            }else{
                if(s.size()){
                    res.insert(s);
                }
                if(nz){
                    res.insert("0");
                }
                s = "";
            }
        }
        if(s.size()){
            res.insert(s);
        }
        for(const auto& it : res){
            cout<<it<<endl;
        }
        return res.size();
    }
};
