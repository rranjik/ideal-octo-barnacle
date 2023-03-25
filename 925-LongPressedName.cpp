class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<char> rlec;
        vector<int> rlen;
        char l = typed[0];
        int f = 1;
        for(int i = 1; i<typed.size(); i++){
            if(typed[i]==l){
                f++;
            }else{
                rlec.push_back(l);
                rlen.push_back(f);
                f = 1;
                l = typed[i];
            }
        }
        rlec.push_back(l);
        rlen.push_back(f);
        
        vector<char> nrlec;
        vector<int> nrlen;
        l = name[0];
        f = 1;
        for(int i = 1; i<name.size(); i++){
            if(name[i]==l){
                f++;
            }else{
                nrlec.push_back(l);
                nrlen.push_back(f);
                f = 1;
                l = name[i];
            }
        }
        nrlec.push_back(l);
        nrlen.push_back(f);
        
        if(nrlec.size()!=rlec.size())return false;
        for(int i = 0; i<nrlec.size(); i++){
            if(nrlec[i]!=rlec[i]) return false;
            if(rlen[i]<nrlen[i]) return false;
        }
        return true ;
    }
};
