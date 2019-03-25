#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findroot(int rt, vector<int>& roots){
    if(roots[rt]!=rt) roots[rt]=findroot(roots[rt], roots);
    return roots[rt];
}

int main() {
    int n, q;
    cin>>n;
    vector<int> roots(n);
    vector<int> counts(n, 1);
    for(int i=0; i<roots.size(); i++){
        roots[i]=i;
    }

    cin>>q;
    while(q){
        char ins;
        cin>>ins;
        switch(ins){
            case 'M':{
                int p1, p2;
                cin>>p1>>p2;
                auto rp1 = findroot(p1-1, roots);
                auto rp2 = findroot(p2-1, roots);
                if(rp1!=rp2){
                    roots[rp1] = rp2;
                    counts[rp2] += counts[rp1];
                }
            }break;
            case 'Q':{
                int p;
                cin>>p;
                cout<<counts[findroot(p-1, roots)]<<endl;
            }break;
        }
        q--;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
