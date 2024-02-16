#include <bits/stdc++.h>
using namespace std;
int a[102],dp[102],vet[102];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("inp.inp","r",stdin);
	freopen("inp.out","w",stdout);
	int n,s;cin>>n>>s;
	vector <int> v;
	for (int i = 1;i<=n;i++) cin>>a[i];
	dp[0] = 1;
	for (int i = 1;i<=n;i++)
		for (int j = s;j>=a[i];j--){
			if (dp[j-a[i]]==1 && dp[j] == 0){
				dp[j] = 1;
				vet[j] = i;
			}
		}
	if(dp[s]==0) cout<<"NO";
	else{
		cout<<"YES"<<'\n';
		int j = s;
		while (j>0){
			v.push_back(vet[j]);
			// cout<<j<<' ';
			j = j - a[vet[j]];
		}
		for (auto x : v) cout<<x<<' ';
		
	}

	return 0;
}