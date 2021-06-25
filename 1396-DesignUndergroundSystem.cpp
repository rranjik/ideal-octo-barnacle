//struct checkin{
//    string s;
//    int t;
//    checkin(string _s, int _t):s(_s), t(_t){}
//};
//struct stat{
//    int d;
//    int s;
//    stat(int _d, int _s):d(_d), s(_s){}
//};
using checkin = pair<string, int>;
using stat = pair<int, int>;
class UndergroundSystem {
public:
    unordered_map<string, unordered_map<string, stat>> f;
    unordered_map<int, checkin> in;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto chin = in[id];
        string chinstation = chin.first;
        int chintime = chin.second;
        auto totaltime = t - chintime;
        in.erase(in.find(id));
        if(f.find(chinstation)!=f.end()&&f[chinstation].find(stationName)!=f[chinstation].end()){
            auto oldstat = f[chinstation][stationName];
            oldstat.first++;
            oldstat.second+=totaltime;
            f[chinstation][stationName] = oldstat; 
        }else{
            f[chinstation][stationName] = make_pair(1, totaltime);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        if(f.find(startStation)!=f.end()&&f[startStation].find(endStation)!=f[endStation].end()){
            auto st = f[startStation][endStation];
            return ((1.0)*st.second)/st.first;
        }
        return 0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
