using coor = pair<int, int>;
class config{
    public:
        int i; coor f1; coor f2;
        config(int _i, coor _f1, coor _f2):i(_i), f1(_f1), f2(_f2){}
        bool operator==(const config& c) const {
            return (i==c.i)&&(f1==c.f1)&&(f2==c.f2);
        }
    
};
namespace std{
    template<>
    struct hash<config>{
        size_t operator()(const config& c) const {
             return (hash<int>()(c.i)^0x58927592)^
             (hash<int>()(c.f1.first)^0x89574979)^
             (hash<int>()(c.f1.second)^0x20583048)^
             (hash<int>()(c.f2.first)^0x295947281)^
             (hash<int>()(c.f2.second)^0xF938E8497);
        }
    };
}
class Solution {
public:
    static map<char, coor> kb;
    string word;
    int dist(coor c1, coor c2){
        if((c1.first == -1)&&(c1.second==-1)) return 0;
        return (abs(c1.first - c2.first) + abs(c1.second - c2.second));
    }
    unordered_map<config, int> c;
    int dp(int i, coor f1, coor f2){
        config co = config(i, f1, f2);
        if(c.find(co)!=c.end()) return c[co];
        //cout<<"dp("<<i<<")"<<"f1 = ("<<f1.first<<", "<<f1.second<<")"<<"; f2 = ("<<
            //f2.first<<", "<<f2.second<<")"<<"; word[i]"<<word[i]<<"kb[word[i]] = "<<
            //kb[word[i]].first<<", "<<kb[word[i]].second<<endl;
        if(i>=word.size()) {
            c[co] = 0;
            return 0;
        }
        int res = numeric_limits<int>::max();
        res = min(dp(i+1, kb[word[i]], f2)+dist(f1, kb[word[i]]), dp(i+1, f1, kb[word[i]])+dist(f2, kb[word[i]]));
        c[co] = res;
        return res;
    }
    int minimumDistance(string word) {
        this->word = word;
        //for(char i = 'a'; i<='z'; i++){
        //    auto c = kb[i];
        //    cout<<c.first<<" "<<c.second<<endl;
        //}
        coor f1{-1, -1};
        coor f2{-1, -1};
        return dp(0, f1, f2);
    }
};

map<char, coor> Solution::kb = {
        {'A', {0,0}},
        {'B', {0,1}},
        {'C', {0,2}},
        {'D', {0,3}},
        {'E', {0,4}},
        {'F', {0,5}},
        {'G', {1,0}},
        {'H', {1,1}},
        {'I', {1,2}},
        {'J', {1,3}},
        {'K', {1,4}},
        {'L', {1,5}},
        {'M', {2,0}},
        {'N', {2,1}},
        {'O', {2,2}},
        {'P', {2,3}},
        {'Q', {2,4}},
        {'R', {2,5}},
        {'S', {3,0}},
        {'T', {3,1}},
        {'U', {3,2}},
        {'V', {3,3}},
        {'W', {3,4}},
        {'X', {3,5}},
        {'Y', {4,0}},
        {'Z', {4,1}},
    };
