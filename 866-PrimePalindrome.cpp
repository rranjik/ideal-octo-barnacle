class Solution {
public:
    auto isPrime(int n){
        if(n<=1) return false;
        for(int i = 2; i <=sqrt(n); i++){
            if(!(n%i)) return false;
        }
        return true;
    }
    auto isPal(int i, int j, const string& s){
        if(i>=j) return true;
        if(s[i]==s[j]) return isPal(i+1, j-1, s);
        return false;
    }
    int primePalindrome(int N) {
        for(int rootLen = 1; rootLen<6; rootLen++){
            for(int root = (int)(pow(10, rootLen-1)); root<(int)(pow(10, rootLen)); root++){
                auto rootstr = to_string(root);
                auto revrootoffone = rootstr.substr(0, rootstr.length()-1);
                reverse(revrootoffone.begin(), revrootoffone.end());
                cout<<rootstr+revrootoffone<<endl;
                if(stoi(rootstr+revrootoffone)>=N&&
                   isPrime(stoi(rootstr+revrootoffone))){
                    if(N<=11) return min(stoi(rootstr+revrootoffone), 11);
                    else return stoi(rootstr+revrootoffone);
                }
            }
            for(int root = (int)(pow(10, rootLen-1)); root<(int)(pow(10, rootLen)); root++){
                auto rootstr = to_string(root);
                auto revroot = rootstr;
                reverse(revroot.begin(), revroot.end());
                cout<<rootstr+revroot<<endl;
                if(stoi(rootstr+revroot)>=N&&
                   isPrime(stoi(rootstr+revroot))){
                if(isPrime(stoi(rootstr+revroot))) return stoi(revroot+rootstr);
                }
            }
        }
        return 0;
    }
    //int primePalindrome(int N) {
    //    for(int i = N; i<numeric_limits<int>::max(); i++){
    //        string s = to_string(i);
    //        if(isPal(0, s.length()-1, s)&&isPrime(i)) return i;
    //    }
    //    return 0;
    //}
};
