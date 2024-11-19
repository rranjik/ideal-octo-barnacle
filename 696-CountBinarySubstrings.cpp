class Solution {
public:
    /*
    00110011
    12101210
    */
    int countBinarySubstrings(string s) {
        int nz = 0;
        int no = 0;
        char last = ' ';
        int res = 0;
        s+=' ';
        for(int i = 0; i<s.size(); i++){
            //cout<<"no = "<<no<<" nz = "<<nz<<endl;
            char c = s[i];
            if(c!=last){
                res += min(nz, no);
                if(c=='0'){
                    nz = 1;
                }else{
                    no = 1;
                }
            }else {
                if(c=='0') nz++;
                else no++;
            }
            last = c;
        }
        return res;
    }
};
