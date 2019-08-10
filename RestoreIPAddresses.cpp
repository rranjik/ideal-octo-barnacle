class Solution {
public:
    vector<string> res;
    string s;
    void vdp(int segs,const int ptr, vector<int> p){
        if(segs == 4 && ptr == s.length()){ 
            res.push_back(
                string(to_string(p[0])+"."+
                       to_string(p[1])+"."+
                       to_string(p[2])+"."+
                       to_string(p[3])));
            return;
        }else{
            if(segs<4){
                for(int l=1; l<=3 && ptr+l<=s.length(); l++){
                    int part = stoi(string(s.begin()+ptr, s.begin()+ptr+l));
                    cout<<"part: "<<part<<"; ptr: "<<ptr<<endl;
                    if(part>=0 && part<256){
                            p.push_back(part);
                            vdp(segs+1, ptr+l, p);
                            p.pop_back();
                    }
                }
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        vdp(0, 0, vector<int>());
        return res;
    }
};
