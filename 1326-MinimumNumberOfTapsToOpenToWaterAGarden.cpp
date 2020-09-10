class inter{
    public:
        int s;
        int e;
        inter(int _s, int _e):s(_s), e(_e){}
        bool operator<(const inter& i) const {
            if(s==i.s) return e<i.e;
            return s<i.s;
        }
};
class interindex {
    public:
        int index;
        int e;
    interindex(int a, int b):index(a), e(b) {}
    bool operator<(const interindex& i)const{
        return e<i.e;
    }
};
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<inter> inters;
        for(int i = 0; i<ranges.size(); i++){
            inters.push_back(inter(i-ranges[i], i+ranges[i]));
        }
        sort(inters.begin(), inters.end());
        for(const auto& i : inters){
            cout<<i.s<<" "<<i.e<<endl;
        }

        priority_queue<interindex> q;
        int mini = numeric_limits<int>::max();
        for(int i = 0; i<inters.size(); i++){
            cout<<"examining "<<inters[i].s<<" "<<inters[i].e<<endl;
            if(q.empty()){
                cout<<"q was empty "<<endl;
                q.push(interindex(i, inters[i].e));
            }
            else{
                if(q.top().e<n){
                    if(inters[i].s>q.top().e) return -1;
                    if(inters[i].e>q.top().e){
                         auto popped = q.top();
                         q.pop();
                        if(!q.empty()){
                         if(q.top().e>=inters[i].s){
                             q.push(interindex(i, inters[i].e));
                         }else {
                             q.push(popped);
                             q.push(interindex(i, inters[i].e));
                         }
                        }else {
                            if(inters[i].s<=0) {
                                 q.push(interindex(i, inters[i].e));
                            }
                            else if(inters[popped.index].s<inters[i].s){
                             q.push(popped);
                             q.push(interindex(i, inters[i].e));
                            }else {
                             q.push(interindex(i, inters[i].e));
                            }
                        }
                    }
                }
            }
                       mini = min(mini,(int) q.size());
            cout<<"top "<<q.top().e<<endl;
            cout<<"q size "<<q.size()<<endl;
        }
        if(q.top().e>=n) 
                       return q.size();
        else return -1;
    }
};
