class ZigzagIterator {
public:
    int lastAccessed;
    vector<vector<int>::iterator> its;
    vector<vector<int>::iterator> itse;
    int k;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        k = 0;
        if(v1.size()){its.push_back(v1.begin()); k++;}
        if(v2.size()){its.push_back(v2.begin()); k++;}
        if(v1.size())itse.push_back(v1.end());
        if(v2.size())itse.push_back(v2.end());
        lastAccessed = k-1;
    }

    int next() {
        cout<<"lastAccess was "<<lastAccessed<<endl;
        int toAccess = (lastAccessed+1)%k;
        cout<<"toAccess = "<<toAccess<<endl;
        while(its[toAccess]==itse[toAccess]) toAccess = (toAccess+1)%k;
        cout<<"final toAccess = "<<toAccess<<endl;
        auto res = *its[toAccess];
        its[toAccess]++;
        lastAccessed = toAccess%k;
        cout<<"next() returns "<<res<<endl;
        return res;
    }

    bool hasNext() {
        if(!k) return false;
        int i = 0;
        while(i<k&&(its[i]==itse[i])){
            
            i++;
        }
        if(i==k) {
            cout<<"hasNext returns false"<<endl;
            return false;
        }
        else {
            cout<<"hasNext returns true"<<endl;
            return true;
        }
        
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
