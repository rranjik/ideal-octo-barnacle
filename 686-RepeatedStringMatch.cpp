class Solution {
public:
    struct rollinghash{
        long long m = (1l<<31)-1;
        int len{};
        int b = 256;//ascii
        long long bpowlen1modm = 1;//use repeatedly in skip
        rollinghash(int _l){
            len = _l;
            for(int i = 1; i<=_l-1; i++){
                bpowlen1modm*=b;
                bpowlen1modm%=m;
            }
        }
        long long h{};
        void append(char c){
            int v = static_cast<int>(c);
            h*=b;
            h%=m;
            h+=v;
            h%=m;
        }
        void skip(char c){
            int v = static_cast<int>(c);
            h-=((v*bpowlen1modm)%m);
            //h%=m;
            h+=m;
            h%=m;
        }
    };
    int repeatedStringMatch(string A, string B) {
        if(A.find(B)!=string::npos)return 1;
        int n{};
        if(B.length()%A.length()){
            n = B.length()/A.length();
            n++;
        }else {
            n = B.length()/A.length();
        }
        string a;
        for(int i = 1; i<=n ; i++) a+=A;
        //cout<<"n = "<<n<<endl;
        //cout<<"a = "<<a<<endl;
        rollinghash rb(B.length());
        for(const auto& c : B) {
            rb.append(c);
        }
        //cout<<endl;
        rollinghash ra(B.length());
        for(int i = 0; i<B.length(); i++) {
            ra.append(a[i]);
        }
        //cout<<"before rah = "<<ra.h<<" rbh = "<<rb.h<<endl;
        if(ra.h==rb.h) {
            if(a.substr(0, B.length())==B)
                return n;
        }
        for(int i = B.length(); i<a.length(); i++){
            ra.skip(a[i-B.length()]);
            ra.append(a[i]);
            //cout<<"rolling rah = "<<ra.h<<" rbh = "<<rb.h<<endl;
            if(ra.h==rb.h){
                if(a.substr(i-B.length()+1, B.length())==B)
                    return n;
            }
        }
        //n++;
        //a = string();
        //for(int i = 1; i<=n ; i++) a+=A;
        ////cout<<"n = "<<n<<endl;
        ////cout<<"a = "<<a<<endl;
        //rollinghash ra2(B.length());
        //for(int i = 0; i<B.length(); i++) ra2.append(a[i]);
        //if(ra2.h==rb.h) {
        //    if(a.substr(0, B.length())==B)
        //        return n;
        //}
        ////cout<<"before ra2h = "<<ra2.h<<" rbh = "<<rb.h<<endl;
        //for(int i = B.length(); i<a.length(); i++){
        //    ra2.skip(a[i-B.length()]);
        //    ra2.append(a[i]);
        //    //cout<<"rolling ra2h = "<<ra2.h<<" rbh = "<<rb.h<<endl;
        //    if(ra2.h==rb.h){
        //        if(a.substr(i-B.length()+1, B.length())==B){
        //            //cout<<"equal!!!"<<endl;
        //            return n;
        //        }
        //    }
        //}
        return -1;
    }
};
