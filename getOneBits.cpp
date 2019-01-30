/*
 * Complete the 'getOneBits' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

vector<int> getOneBits(int n) {
    int count =0; //number if bits set to one
    int pos=0; //number of total bits 
    vector<int> poss; //positions - to hold positions (positions indexed from right)
    while (n) {
        pos++; //increment number of bits 
      if (n & 1) { //of bitwise anding this is 1 then the last bit is set
        count ++; //increment count
        poss.push_back(pos); //make note of the position 
      } 
      n >>= 1;//throw away the last bit that was examined now and shift everythign to right
    }
    for(auto& position:poss){
        position = abs(pos-position)+1; // account for the indexing from right
    }
    vector<int> res;//it is an overkill to create a new vector for the sake of this but since numbers are small it's okay
    res.push_back(count);//push the count
    reverse(poss.begin(), poss.end());
    for (auto &position : poss) {
      res.push_back(position);//push the positioss
    }
    return res;
}
