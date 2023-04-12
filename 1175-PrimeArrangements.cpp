class Solution {
public:
    int numPrimeArrangements(int n) {
                            //0 1 2 3 4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        //if n == 20 then we get 23 and its index, 8 tells the number of primes (np) <= 20 
        //if n == 2 then we get 3 and its index is 1 (which is the number of primes before 3 by virtue
        //of 0-indexing) and it tells the numer of primes <= n
        int np = upper_bound(begin(primes), end(primes), n)-primes.begin();
        long long m = 1e9+7;
        long long res = 1;
        //primes can mingle among each other; there are np primes and np positions 
        //so np! permutations 
        for(int i = 1; i<=np; i++) {
            res*=i;
            res%=m;
        }
        //n minus number of primes is the number of composites 
        //|||ly for composites; nc composites can mingle as they like in the nc posistions
        auto nc = n-np;
        for(int i = 1; i<=nc; i++) {
            res*=i;
            res%=m;
        }
        //result is the permutation of primes times the permutations of composites
        //think: pick a perm of primes of your choice and pick some perm of composites 
        return res;
    }
};
