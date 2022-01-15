class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> ns;
        for(int i = 0; i<s.size();){
            int h = 0;
            while(i<s.size()&&isdigit(s[i])){
                h*=10;
                h+=(s[i]-'0');
                i++;
            }
            i++;
            if(h&&ns.size()&&ns.back()>=h) return false;
            if(h) ns.push_back(h);
        }
        for(const auto& n : ns) cout<<n<<" ";
        cout<<endl;
        return true;
    }
};
