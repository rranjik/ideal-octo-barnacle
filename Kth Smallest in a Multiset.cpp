// you can use includes, for example:
// #include <algorithm>

#include <set>
#include <cmath>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &X, vector<int> &Y) {
    // write your code in C++14 (g++ 6.2.0)
    multiset<double> tree;
    for(size_t i = 0; i<X.size(); ++i){
        auto distance = sqrt((X[i]*X[i])+(Y[i]*Y[i]));
        // cout<<"inserting: "<<distance<<endl;
        tree.insert(distance);
    }
    // int count = 1;
    // for(auto it=tree.begin(); it!=tree.end();it++){
    //     cout<<"tree["<<count<<"]: "<<*it<<endl;
    //     count++;
    // }
    auto start = tree.begin();
    
    for(int i=0; i<K-1;i++)
        start++;
    auto kthSmallest = *start;
    // cout<<"kthSmallest"<<kthSmallest<<endl;
    // cout<<"ceil(kthSmallest)"<<ceil(kthSmallest)<<endl;
    return ceil(kthSmallest);
}
