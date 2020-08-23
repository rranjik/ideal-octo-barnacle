class val{
public:
    string value;
    int t;
    bool operator<(const val& v) const{
        return t<v.t;
    }
    val(string _value, int _t):value(_value), t(_t){}
};
class TimeMap {
public:
    /** Initialize your data structure here. */
    map<string, vector<val>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto v = val(value, timestamp);
        if(m.find(key)==m.end()){
            m[key].push_back(v);
        }else{
            m[key].insert(upper_bound(begin(m[key]), end(m[key]), v), v);
        }
        //for(auto it=m.begin(); it!=m.end(); it++){
        //    cout<<it->first<<" ";
        //    for(const auto& va : it->second){
        //        cout<<va.value<<"@"<<va.t<<"; ";
        //    }
        //    cout<<endl;
        //}
    }
    
    string get(string key, int timestamp) {
        auto dv = val("", timestamp);
        if(m.find(key)==m.end()) return "";
        auto it = upper_bound(begin(m[key]), end(m[key]), dv);
        if(it!=end(m[key])){
            //cout<<"found an upper_bound "<<(*it).value<<"@"<<(*it).t<<endl;
        }
        if(it==begin(m[key])){
            //cout<<"no upper bound found!"<<endl;
            return "";
        }
        it--;
        //if(it!=(m[key].end())){
        return (*it).value;
        //}else {
        //    return "";
        //}
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
