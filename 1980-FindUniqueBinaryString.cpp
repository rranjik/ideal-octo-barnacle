class Solution {
public:
    void del(unordered_set<string>& s, int i, char v){
        unordered_set<string> ret;
        for(const auto& n : s){
            if(n[i]==v) {
            }else{
                ret.insert(n);
            }
        }
        s = ret;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(), nums.end());
        string res;
        int nz = 0;
        int no = 0;
        for(int i = 0; i<nums.size(); i++){
            nz= 0; no = 0;
            for(const auto& n : s){
                if(n[i]=='0'){
                    nz++;
                }else{
                    no++;
                }
            }
            cout<<"no = "<<no<<" nz = "<<nz<<endl;
            if(no>nz){
                res+='0';
                del(s, i, '1');
            }else{
                res+='1';
                del(s, i, '0');
            }
            cout<<"res = "<<res<<endl;
        }
        return res;
    }
};
