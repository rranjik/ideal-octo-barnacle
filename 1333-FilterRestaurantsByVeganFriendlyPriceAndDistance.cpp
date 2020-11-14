class Restaurant{
public:
    int id;
    int rating;
    int distance;
    int price;
    int vegan;
    Restaurant(int i, int r, int d, int p, int v):id(i), rating(r), distance(d), price(p), vegan(v){}
    bool operator<(const Restaurant& r) const{
        if(r.rating==rating){
            return id>r.id;
        }
        return rating>r.rating;
    }
};
class Solution {
public:
    
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<Restaurant> rs;
        for(const auto& r : restaurants){
            Restaurant res(r[0], r[1], r[2], r[3], r[4]);
            if((r[3]<=maxPrice)&&(r[4]<=maxDistance)){
                cout<<"res "<<r[0]<<"past dist and price"<<endl;
                if(veganFriendly&&r[2]){
                    cout<<"adding restaurant "<<r[0]<<endl;
                    rs.insert(upper_bound(rs.begin(), rs.end(), res), res);
                }else if(!veganFriendly){
                    rs.insert(upper_bound(rs.begin(), rs.end(), res), res);
                }
            }
        }
        vector<int> res;
        for(const auto& r : rs){
            res.push_back(r.id);
        }
        return res;
    }
};
