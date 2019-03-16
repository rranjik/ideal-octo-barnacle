
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin>>q;
    queue<int> Q;
    while(q){
        int q_type;
        cin>>q_type;
        switch(q_type){
            case 1:{
                int num;
                cin>>num;
                Q.push(num);
            } break;
            case 2:{
                Q.pop();
            } break;
            case 3:{
                cout<<Q.front()<<endl;
            }break;
            default:
                break;
        }
        q--;
    }
    return 0;
}
