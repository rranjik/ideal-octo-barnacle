int solution(vectorint &S, vectorint &E) {
     write your code in C++14 (g++ 6.2.0)
    sort(S.begin(), S.end());
    sort(E.begin(), E.end());
    int chairs = 0;
    int count = 0;
    size_t i=0;
    size_t j=0;
    while(iS.size()){
        either i or j increments everytime
        ensures that we terminate
        if(S[i]E[j]){
            chairs = max(chairs, ++count);
            i++;
        }
        else{
            count--;
            j++;
        }
    }
    return chairs;
}
