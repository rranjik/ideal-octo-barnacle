class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        vector<int> res = vector<int>{-1, -1};
        int S = 0;
        int len = A.size();
        for(const auto& n : A) S+=n;
        if(S%3) return res;
        auto T = S/3;
        if(!T) return {0, len-1};
        int i1 = -1, j1 = -1, i2 = -1, j2 = -1, i3 = -1, j3 = -1;
        int c = 0;
        for(int i = 0; i<A.size(); i++){
            if(A[i]){
                c+=1;
                if(c == 1) i1 = i;
                if(c == T) j1 = i;
                if(c == T+1) i2 = i;
                if(c == 2*T) j2 = i;
                if(c == 2*T+1) i3 = i;
                if(c == 3*T) j3 = i;
            }
        }
        
        auto p1 = vector<int>(A.begin()+i1, A.begin()+j1+1);
        auto p2 = vector<int>(A.begin()+i2, A.begin()+j2+1);
        auto p3 = vector<int>(A.begin()+i3, A.begin()+j3+1);
        
        if(p1!=p2||p1!=p3) return res;
        
        int x = i2-j1-1;
        int y = i3-j2-1;
        int z = len-j3-1;
        
        if(x<z||y<z) return res;
        return {j1+z, j2+z+1};
    }
};
