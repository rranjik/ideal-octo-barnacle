#include <bits/stdc++.h>

using namespace std;

// long long int Ms[] = {
//     0,
//     1,
//     1,
//     1,
//     2,
//     3,
//     4,
//     5,
//     7,
//     10,
//     14,
//     19,
//     26,
//     36,
//     50,
//     69,
//     95,
//     131,
//     181,
//     250,
//     345,
//     476,
//     657,
//     907,
//     1252,
//     1728,
//     2385,
//     3292,
//     4544,
//     6272,
//     8657,
//     11949,
//     16493,
//     22765,
//     31422,
//     43371,
//     59864,
//     82629,
//     114051,
//     157422,
//     217286
// };

int answers[] = {
0,
0,
0,
0,
1,
2,
2,
3,
4,
4,
6,
8,
9,
11,
15,
19,
24,
32,
42,
53,
68,
91,
119,
155,
204,
269,
354,
462,
615,
816,
1077,
1432,
1912,
2543,
3385,
4522,
6048,
8078,
10794,
14475,
19385,
};
// long long int primes_up_to[217286];
// primes_up_to[0]=0;
// primes_up_to[1]=0;
// primes_up_to[2]=1;
// primes_up_to[3]=2;
// primes_up_to[4]=2;


// bool is_prime(long long int n){
//     if(n==1||n==0)
//         return false;
//     else if(n==2||n==3)
//         return true;
//     else{
//         long long int sqrrt = ceil(sqrt(n));
//         for(long long int i=2; i<=sqrrt; i++)
//         {
//             if(n%i==0)
//                 return false;
//         }
//         return true;
//     }
// }

// int count_primes_up_to_n(long long int n){
//     // if(primes_up_to[n]!=-1)
//     //     return primes_up_to[n];

//     long long int ans = 0;
//     for(long long int i=0;i<=n;i++){
//         if(is_prime(i))
//             ans++;
//     }
//     //primes_up_to[n]=ans;
//     cout<<ans<<endl;
//     return 0;
// }

// // Complete the redJohn function below.
// int redJohn(int n) {
//     long long int n1 = 1;
//     long long int n2 = 1;
//     long long int n3 = 1;
//     long long int n4 = 2;
//     long long int ans =0;
//     if(n==1||n==2||n==3)
//         {
//             cout<<1<<endl; 
//             return 0;
//         }    
//     else if(n==4){
//         cout<<2<<endl;
//         return 0;
//     }
//     else{
//         for(int i = 5; i<=n; i++){
//             ans = n1 + n4;
//             n1=n2;
//             n2=n3;
//             n3=n4;
//             n4=ans;
//         }
//         cout<<ans<<endl;
//         return 0;
//     }
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // for(int i=0;i<217286;i++){
        //     primes_up_to[i]=-1;
        // }

        // primes_up_to[0]=0;
        // primes_up_to[1]=0;
        // primes_up_to[2]=1;
        // primes_up_to[3]=2;
        // primes_up_to[4]=2;

        // for(int i=0;i<=41;i++)
        // {
        //     count_primes_up_to_n(Ms[i]);
        // }

        //for(int i = 1; i<=40; ++i)
        //int result = redJohn(i);



        fout << answers[n] << "\n";
    }

    fout.close();

    return 0;
}
