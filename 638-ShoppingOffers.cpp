struct Needs{
    int _1; int _2; int _3; int _4; int _5; int _6;
    Needs(int __1, int __2, int __3, int __4, int __5, int __6):
    _1(__1), _2(__2), _3(__3), _4(__4), _5(__5), _6(__6){}
    bool operator==(const Needs& n) const {
        return _1==n._1&&_2==n._2&&_3==n._3&&_4==n._4&&_5==n._5&&_6==n._6;
    }
    inline int convert() const {
        //cout<<"converting "<<_1<<" "<<_2<<" "<<_3<<" "<<_4<<" "<<_5<<" "<<_6<<endl;
        int res = _1+(_2*7)+(_3*7*7)+(_4*7*7*7)+(_5*7*7*7*7)+(_6*7*7*7*7*7);
        //cout<<"converted to "<<res;
        return res;
    }
    
};
namespace std{
    template <>
    struct hash<Needs>{
        size_t operator()(const Needs& n) const {
            return (hash<int>()(n._1)^0x28482928)^
            (hash<int>()(n._2)^0x95292749)^
            (hash<int>()(n._3)^0x20948203)^
            (hash<int>()(n._4)^0x59483928)^
            (hash<int>()(n._5)^0x81439349)^
            (hash<int>()(n._6)^0x10538493);
        }
    };
}
class Solution {
public:
    vector<vector<int>> offers;
    bool canApply(const vector<int>& needs, const vector<int>& offer){
        for(int i = 0; i<needs.size(); i++){
            if(needs[i]<offer[i])
                return false;
        }
        return true;
    }
    int apply(vector<int>& needs, const vector<int>& offer)const{
        for(int i = 0; i<needs.size(); i++){
            needs[i]-=offer[i];
        }
        return offer[offer.size()-1];
    }
    void revoke(vector<int>& needs, const vector<int>& offer)const{
        for(int i = 0; i<needs.size(); i++){
            needs[i]+=offer[i];
        }
    }
    vector<int> cache;
    unordered_map<Needs, int> c;
    int dp(vector<int> needs){
        int need = 0;
        vector<int> nee(6, 0);
        for(int i = 0; i<needs.size(); i++){
            need+=needs[i];
            //cout<<needs[i]<<" ";
            nee[i] = needs[i];
        }
        //cout<<"here a"<<endl;
        for(int i = needs.size(); i<6; i++){
            nee[i] = 0;
        }
        //cout<<"here b"<<endl;
        auto ne = Needs(nee[0], nee[1], nee[2], nee[3], nee[4], nee[5]);
        int nnnn = ne.convert();
        //cout<<"nnnn"<<nnnn<<endl;
        if(cache[nnnn]!=-1) return cache[nnnn];
        //if(c.find(ne)!=c.end()) return c[ne];
        //cout<<endl;
        //cout<<"here c"<<endl;
        if(!need){
            cache[nnnn] = 0;
            //c[ne] = 0;
            return 0;
        }
        int res = inner_product(needs.begin(), needs.end(), price.begin(), 0); //numeric_limits<int>::max();
        //cout<<"here 1"<<endl;
        for(int i = 0; i<offers.size(); i++){
            if(offers[i].back()>= res) continue;
            bool doi = true;
            for(int j = 0; j<needs.size(); j++){
                if(needs[j]<offers[i][j]){
                    doi = false;
                    break;
                }
            }
            if(!doi) continue;  
            //if(canApply(needs, offers[i])){
            
        //cout<<"here 2"<<endl;
            for(int j = 0; j<needs.size(); j++){
                needs[j]-=offers[i][j];
            }
                //auto cost = apply(needs, offers[i]);
                auto ret = dp(needs);
                //cout<<"needs: ";
                //for(int i = 0; i<needs.size(); i++){
                //    cout<<needs[i]<<" ";
                //}
                //cout<<"returned "<<ret<<endl;
        //cout<<"here 2.25"<<endl;
                res=min(res, ret+offers[i][offers[i].size()-1]);
        //cout<<"here 2.5"<<endl;
                //revoke(needs, offers[i]);
            for(int j = 0; j<needs.size(); j++){
                needs[j]+=offers[i][j];
            }
        //cout<<"here 3"<<endl;
            //}
        }
        //cout<<"here 4"<<endl;
        cache[nnnn] = res;
        //c[ne] = res;
        return res;
    }
    vector<int> price;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        cache = vector<int>(117649, -1);
        this->price = price;
        offers.insert(offers.end(), special.begin(), special.end());
        //for(int i = 0; i<price.size(); i++){
        //    vector<int> so(special[0].size(), 0);
        //    so[i] = 1;
        //    so[special[0].size()-1] = price[i];
        //    offers.push_back(so);
        //}
        return dp(needs);
    }
};
