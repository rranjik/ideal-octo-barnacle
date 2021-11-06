class Solution {
public:
    int nextGreaterElement(int n) {
        //return 0;
        int nc = n;
        string ns = to_string(n);
        int nd = 0;
        vector<int> ds;
        while(nc){
            int d = nc%10;
            ds.push_back(d);
            nc/=10;
            nd++;
        }
        reverse(ds.begin(), ds.end());
        vector<vector<int>> choices(nd);
        bool canChoose = false;
        for(int i = 0; i<nd; i++){
            for(int j = i+1; j<nd; j++){
                if(ds[j]>ds[i]){
                    choices[i].push_back(ds[j]);
                    canChoose = true;
                }
            }
        }
        cout<<"after computing choices "<<endl;
        for(int i = 0; i<nd; i++){
            sort(choices[i].begin(), choices[i].end());
        }
        cout<<"after sorting choices "<<endl;
        for(int i = 0; i<nd; i++){
            cout<<"choices for "<<ds[i]<<": ";
            for(const auto& c : choices[i]){
                cout<<c<<" ";
            }
            cout<<endl;
        }
        if(!canChoose) return -1;
        int res;
        cout<<"examining choices "<<endl;
        for(int i = nd-1; i>=0; i--){
            if(choices[i].size()>0){
                cout<<"making a smaller choice "<<endl;
                string pre = ns.substr(0, i);
                cout<<"pre = "<<pre<<endl;
                pre+=to_string(choices[i][0]);
                cout<<"pre after immediate smaller choice "<<pre<<endl;
                vector<int> tosort;
                int lc = choices[i][0];
                tosort.push_back(ds[i]);
                for(int j = i+1; j<nd; j++){
                    tosort.push_back(ds[j]);
                }
                sort(tosort.begin(), tosort.end());
                cout<<"to sort before removing"<<endl;
                for(const auto& ts : tosort){
                    cout<<ts<<" ";
                }
                cout<<endl;
                tosort.erase(find(tosort.begin(), tosort.end(), choices[i][0]));
                cout<<"to sort after removing "<<endl;
                for(const auto& ts : tosort){
                    cout<<ts<<" ";
                }
                cout<<endl;
                for(const auto& nu : tosort){
                    pre+=to_string(nu);
                }
                try{
                res = stoi(pre);
                }catch(const exception& e){
                    return -1;
                }
                break;
            }
        }
        return res;
    }
};
