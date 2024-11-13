// pi[i] : longest substring being both prefix and suffix
vector <int> prefix_func(vector<int> s){
	int n=(int)s.size();
	vector <int> pi(n,0);
	for(int i=1; i<n; i++){
		int j=pi[i-1];
		while(j and s[i]!=s[j]) j=pi[j-1];
		if(s[i]==s[j]) pi[i]=++j;
	}
	return pi;
}