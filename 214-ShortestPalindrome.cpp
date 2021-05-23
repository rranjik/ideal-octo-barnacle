class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length()==0) return s;
        auto len = s.size();
        vector<int> pi(len);
        int matched = 0;
        for(int i = 1; i<len; i++){
            //one char matched so far, so matched will be 1 (let's say it was s[0])
            //we need to look at s[1] now, which is what i is
            //17 chars matched so far, so matched will be 17 
            //(let's say it was from s[5] .. s[21])
            //we need to look at s[22] now, which is what i is
            while(matched>0&&s[matched]!=s[i]) matched = pi[matched-1];
            if(s[i]==s[matched]) matched++;
            pi[i] = matched;
        }
        matched = 0;
        auto rev = s;
        reverse(begin(rev), end(rev));
        for(int i = 0; i<len; i++){
            while(matched>0&&rev[i]!=s[matched]) matched = pi[matched-1];
            if(rev[i]==s[matched]) matched++;
        }
        cout<<"matched = "<<matched<<endl;
        auto append = rev.substr(0, len-matched);
        append+=s;
        return append;
    }
};
/*
string shortestPalindrome(string s) {
    if(s.empty()) return s;
    int matched=0;
    const auto N=s.size();
    vector<int> back1(N);

    for(int i=1;i<N;i++)
    {
        while(matched>0&&s[i]!=s[matched]) matched=back1[matched-1];
        if(s[i]==s[matched]) matched++;
        back1[i]=matched;
    }
    matched=0;
    for(int i=0;i<N;i++)
    {
        while(matched>0&&s[N-i-1]!=s[matched]) matched=back1[matched-1];
        if(s[N-i-1]==s[matched]) matched++;
    }
    string ret=s.substr(matched);
    reverse(ret.begin(),ret.end());
    ret+=s;
    return ret;
}
*/
