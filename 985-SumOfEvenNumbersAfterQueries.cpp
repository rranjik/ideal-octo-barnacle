class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int odds{};
        int evens{};
        for(const auto& a : A){
            if(a%2) odds++;
            else evens+=a;
        }
        vector<int> res;
        for(const auto& q : queries){
            auto v = q[0];
            auto i = q[1];
            auto old = A[i];
            auto nnew = A[i]+v;
            auto annew = abs(nnew);
            //cout<<"old = "<<old<<" nnew = "<<nnew<<" annew = "<<annew<<endl;
            if(old%2){
                //cout<<"old is odd ";
               if(annew%2){
                   //cout<<" new is also odd; nothing to do"<<endl;
               }else {
                   //cout<<" new is even adding "<<nnew<<endl;
                   evens+=nnew;
               }
            }else{
                //cout<<"old is even ";
               if(!(annew%2)){
                   //cout<<" new is also even adding "<<nnew<<endl;
                   evens-=old;
                   evens+=nnew;
               }else {
                   evens-=old;
                   //cout<<" new is odd substracting "<<old<<endl;
               }
            }
            A[i] = nnew;
            res.push_back(evens);
        }
        return res;
    }
};
