#include <bits/stdc++.h>
using namespace std;
int a[102],b[102],dp[102],vet[102],x[102];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("VALY.inp","r",stdin);
	freopen("VALY.out","w",stdout);
	int n,s;cin>>n>>s;
	for (int i = 1;i<=n;i++) cin>>a[i]>>b[i];
	for (int i = 1;i<=n;i++)
		for (int j = a[i];j<=s;j++)
		{
			if (dp[j]<dp[j-a[i]]+b[i]){
				dp[j] = dp[j-a[i]]+b[i];
				vet[j] = i;
			}
		}
	int j = s;
	while (dp[j]==dp[s]) --j;
	++j;
	for (j;j>0;j-=a[vet[j]]) x[vet[j]]++;
	cout<<dp[s]<<'\n';
	for (int i =0;i<=n;i++) if (x[i]>0) cout<<i<<' '<<x[i]<<'\n';
	return 0;
}