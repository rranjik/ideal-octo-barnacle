class Codec {
public:
    int len(string s){
        int s3 = s[3];
        int s2 = s[2];
        int s1 = s[1];
        int s0 = s[0];
        return (s0*(unsigned long long int)pow(128,3))+
        (s1*(unsigned long long int)pow(128,2))+
        (s2*(unsigned long long int)pow(128,1))+
        (s3*(unsigned long long int)pow(128,0));
    }
    string elen(int len){
        auto lenc = len;
        string res;
        while(len){
            res+=string(1, (int)(len%128));
            len/=128;
        }
        char c{};
        //cout<<"c = "<<(int)c<<endl;
        while(res.size()<4){
            res+=string(1, c);
        }
        reverse(begin(res), end(res));
        cout<<"len = "<<lenc<<"; s[0] = "
            <<(int)res[0]<<"; res[1] = "<<(int)res[1]
            <<"; res[2] = "<<(int)res[2]<<"; res[3] = "
            <<(int)res[3]<<endl;
        return res;
    }
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for(const auto& s : strs){
            res+=elen((int)s.length());
            res+=s;
        }
        cout<<"encode: "<<res<<endl;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        for(int i = 0; i<s.length(); i++){
            auto l = len(string(s.begin()+i, s.begin()+i+4));
            cout<<"l = "<<l<<endl;
            i+=4;
            auto r = string(s.begin()+i, s.begin()+i+l);
            i+=l-1;
            res.push_back(r);
        }
        return res;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
