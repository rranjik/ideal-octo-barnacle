//https://stackoverflow.com/questions/59704715/can-someone-help-me-with-this-question-i-dont-understand-why-is-my-code-not-wo
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
using ull = unsigned long long;

bool canDistribute(ull a, ull b, ull m){
	ull majority = max(a, b);
	ull minority = min(a, b);
	cout<<"majority "<<majority<<" minority "<<minority<<endl;
	ull maxCandiesForMajority = m/minority;
	cout<<"max Candies for majority "<<maxCandiesForMajority<<endl;
	for(ull i = 0; i<=maxCandiesForMajority; i++){
		if(((m-(i*minority))%majority) == 0){
			cout<<"Give the majority "<<i<<" and the minority "<<(m-(i*majority))/minority<<" candies "<<endl;
			return true;
		}
	}
	return false;
}

int main(){
	auto cD = canDistribute(34178971ul, 7382453ul, 727812934ul);
	//auto cD = canDistribute(6, 4, 52);
	cout<<(cD?"Yes":"No")<<endl;
	return 0;
}
