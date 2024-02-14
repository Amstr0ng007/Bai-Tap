#include <bits/stdc++.h>
using namespace std;
#define io(i) freopen("inp.inp","r",stdin);freopen("inp.out","w",stdout);
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[102],b[102],dp[102][102];
vector <int> vet;
void solve(){
	int n,s;cin>>n>>s;
	for (int i = 1;i<=n;i++) cin>>a[i]>>b[i];
	for (int i = 1;i<=n;i++)
		for (int j =1;j<=s;j++){
			dp[i][j] = dp[i-1][j];
			if (b[i]<=j){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-b[i]]+a[i]);
			}
		}
	int j = s;
	for (int i = n;i>0;i--){
		if (dp[i][j]!=dp[i-1][j]){
			j-=b[i];
			vet.push_back(i);
		}
	}
	cout<<dp[n][s]<<'\n'<<vet.size()<<' ';
	for (int i : vet) cout<<i<<' ';
}
int main(){
	io(inp);fio
	int t = 1;
	while (t--){
		solve();
	}
	return 0;
}