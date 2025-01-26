int reduce(int x){
	if(x<10) return x;
	int res = 0;
	while(x){
		res+=(x%10);
		x/=10;
	}
	return reduce(res);
}

int solution(vector<int> r){
	vector<int> red;
	for(const auto& x : r)
		red.push_back(r);
	unordered_map<int, int> m;
	for(const auto& x : red) m[x]++;
	int resc = -1;
	int res = -1;
	for(const auto& [k, v]:m){
		if(resc<v){
			resc==v;
			res = k;
		}else if(resc==v){
			res = max(res, k);
		}
	}
	return res;
}
