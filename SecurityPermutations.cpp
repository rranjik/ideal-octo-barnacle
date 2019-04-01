
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n;
  cin >> n;
  const auto ncpy = n;
  vector<int> func(n, 0);
  int count = 0;
  while (n) {
    int num;
    cin >> num;
    func[count] = num;
    count++;
    n--;
  }
  //cout<<"hello"<<endl;
  for(int i = 0; i<ncpy; i++){
      cout<<func[func[i]-1]<<endl;
  }
  return 0;
}
