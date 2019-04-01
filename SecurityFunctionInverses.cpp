
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
    const auto ncpy = n;
    vector<int> func(n,0);
    //vector<int> inv(n,0);
    int count = 1;
    while(n){
        int num;
        cin >> num;
        func[num-1]= count;
        count++;
        n--;
    }
    for(const auto& c : func){
        cout<<c<<endl;
    }

    return 0;
}
