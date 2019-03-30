
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> func(n, 0);
    const auto ncpy = n;
    while(n){
        int num;
        cin>>num;
        //cout<<"in while loop " << num<<endl;
        if(num<=ncpy)
            func[num-1] = 1;
        else{
            cout<<"NO";
            return 0;
        }
        n--;
    }
    //cout<<"here"<<endl;
    for(const auto& f : func){
        if(!f){
            cout<<"NO";
            return 0;
        }
    }
    cout<< "YES";
    return 0;
}
