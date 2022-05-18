class Solution {
public:
    string toHexspeak(string num) {
        unsigned long long n = stoull(num);
        stringstream stream;
        stream << hex << n;
        string ress( stream.str() );
        transform(ress.begin(), ress.end(), ress.begin(), [](char c){
            if(isalpha(c)) 
                return (char) toupper(c);
            else if(c=='1') return 'I';
            else if(c=='0') return 'O'; 
            else return (char) c; });
        cout<<ress;
        unordered_set<char> allowed = {'A', 'B', 'C', 'D', 'E', 'F', 'I', 'O'};
        for(const auto c : ress){
            if(allowed.find(c)==allowed.end())
                return "ERROR";
        }
        return ress;
    }
};
