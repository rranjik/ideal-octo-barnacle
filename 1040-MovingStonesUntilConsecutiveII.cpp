class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& A) {
        	sort(A.begin(), A.end());
	int n = A.size(), low = n;
        cout<<"n = "<<n<<endl;
	for (int i = 0, j = 0; j < n; ++ j) {
		while (A[j]-A[i]+1 > n)
        {
            //cout<<"A["<<j<<"] = "<<A[j]<<"; A["<<i<<"]"<<A[i]<<endl;
            //cout<<A[j]<<"-"<<A[i]<<"+1 = "<<A[j]-A[i]+1<<endl;
            ++ i;
        }
        //cout<<"i = "<<i<<"; j = "<<j<<endl;
		int already_store = (j-i+1);
        //cout<<"already_store "<<already_store<<endl;
		if (already_store == n - 1 &&  A[j] - A[i] + 1 == n-1) {
			low = min(low, 2);
            //cout<<"hit! low = "<<low<<endl;
		} else {
			low = min(low, n - already_store);
            //cout<<"n - already_store = "<<n - already_store<<endl;
            //cout<<"low = "<<low<<endl;
		}
	}
	return  {low, max(A[n-1]-A[1]-n+1, A[n-2]-A[0]-n+1)};
        //return vector<int>();
    }
};
