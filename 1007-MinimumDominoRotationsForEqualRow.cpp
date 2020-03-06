class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> aa = vector<int>(6,0);
        vector<int> bb = vector<int>(6,0);
        vector<int> d = vector<int>(A.size(), 0);
        bool dp = false;
        for(int i = 0; i<A.size(); i++){
            if(A[i]==B[i]){
                dp = true;
                d[i] = A[i];
            }
        }
        for(const auto& ddd : d){
            cout<<ddd<<" ";
        }
        cout<<endl;
        cout<<boolalpha;
        cout<<"dp = "<<dp<<endl;
        int dv = 0;
        for(const auto& dup :d){
            if(dup){
                if(dv){
                    if(dv!=dup){
                        cout<<"dv = "<<dv<<"; dup = "<<dup<<"failed"<<endl;
                        return -1;
                    }
                }
                else dv = dup;
            }
        }
        cout<<"dv = "<<dv<<endl;
        int nd = 0;
        for(int i = 0; i<A.size(); i++){
            if(A[i]==dv&&B[i]==dv){
                nd++;
            }
            else{
                aa[A[i]-1]++;
                bb[B[i]-1]++;
            }
        }
        for(int i = 0; i<6; i++){
            cout<<"aa["<<i<<"] = "<<aa[i]<<"; bb["<<i<<"] = "<<bb[i]<<endl;
        }
        cout<<"nd = "<<nd<<endl;
        if(nd==A.size()) return 0;
        if(dv){
            if(aa[dv-1]+bb[dv-1]+nd!=A.size()){
                cout<<"aa[dv]+bb[dv]+nd = "<<aa[dv-1]+bb[dv-1]+nd<<" failed"<<endl;
                return -1;
            }
            else {
                cout<<"aa[dv]+bb[dv]+nd = "<<aa[dv-1]+bb[dv-1]+nd<<" passed"<<endl;
                cout<<"aa[dv] = "<<aa[dv-1]<<"; bb[dv] = "<<bb[dv-1]<<endl;
                return min(aa[dv-1], bb[dv-1]);
            }
        }
        else{
            for(int i = 0; i<6; i++){
                if(aa[i]+bb[i] == A.size()){
                    cout<<"i = "<<i<<"added up equal"<<endl;
                    cout<<"aa[i] = "<<aa[i]<<"bb[i] = "<<bb[i]<<endl;
                    return min(aa[i], bb[i]);
                }
            }
        }
        return -1;
    }
};
