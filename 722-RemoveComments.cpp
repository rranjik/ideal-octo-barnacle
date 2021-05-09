class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string l;
        auto inBlock = false;
        for(auto line : source){
            int i = 0;
            if(!inBlock) l = string();
            bool lineComment = false;
            while(!lineComment&&i<line.length()){
                if(inBlock&&i+1<line.length()&&line[i]=='*'&&line[i+1]=='/'){
                    inBlock = false;
                    i++;
                }else if(!inBlock&&i+1<line.length()&&line[i]=='/'&&line[i+1]=='*'){
                    inBlock = true;
                    i++;
                }else if(!inBlock&&i+1<line.length()&&line[i]=='/'&&line[i+1]=='/'){
                    lineComment = true;
                }else if(!inBlock){
                    l+=line[i];
                }
                i++;
            }
            if(!inBlock&&l.length()>0) res.push_back(l);
        }
        return res;
    }
};
