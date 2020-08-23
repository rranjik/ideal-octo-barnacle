class Solution {
public:
    array<int, 10> count(int n){
        cout<<"n = "<<n<<endl;
        array<int, 10> f{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        while(n){
            int d = n%10;
            f[d]++;
            n/=10;
        }
        return f;
    }
    bool reorderedPowerOf2(int N) {
        set<array<int, 10>> powerof2;
        for(unsigned long long i = 1; i<numeric_limits<int>::max(); i++){
            powerof2.insert(count(i));
            i<<=1;
            i-=1;
        }
        for(const auto& a : powerof2){
            for(int i = 0; i<10; i++){
                cout<<i<<"-"<<a[i]<<" "; 
            }
            cout<<endl;
        }
        return powerof2.find(count(N))!=powerof2.end();
        //return false;
    }
};
