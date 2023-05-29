class Solution {
public:
    int findTheWinner(int n, int K) {
        int ndead = 0;
        vector<int> f(n);
        for(int i = 0; i<n; i++) f[i] = i+1;
        int i = 0;
        int k = 0;
        while(ndead<n-1){
            //cout<<"starting againg at i = "<<i<<endl;
            while(k<K){
                if(f[i]){
                    //cout<<"counting i = "<<i<<"; k = "<<k<<endl;
                    k++;
                }
                if(k<K){
                    i++;
                    i%=n;
                }
            }
            //cout<<"killed i = "<<i<<endl;
            ndead++;
            f[i] = 0;
            k = 0;
            while(!f[i]){
                i++; i%=n;
            }
        }
        for(int i = 0; i<n; i++){
            if(f[i]) return f[i];
        }
        return -1;
    }
};
