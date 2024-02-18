#include <bits/stdc++.h>
using namespace std;
int a[1002][1002],dp[1002][1002];
int INF = -1e6+5;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("inp.inp","r",stdin);
	freopen("inp.out","w",stdout);
	int n,m;cin>>n>>m;
	// return 0;
	vector <int> vet;
	// goi dp[i][j] la cach di nhat dc nhieu rac nhat den vi tri i,j
	// th co so dp[i][0] dp[0][j]
	for (int i = 1;i <= n;i++)
		for (int j =1;j<=m;j++)
			cin>>a[i][j];
	for (int i = 0;i<=n;i++) dp[i][0] = INF;
	for (int i = 0;i<=m;i++) dp[0][i] = INF;
	for (int i = 1;i<=m;i++) dp[1][i] = a[1][i];
	for (int i = 2;i <= n;i++)
		for (int j =1;j<=m;j++)
		{
			dp[i][j] = max(dp[i-1][j+1],max(dp[i-1][j],dp[i-1][j-1])) + a[i][j];
		}
	int x = 0,y = 0;
	for (int i = 1;i<=m;i++){
		if (x<dp[n][i]){
			x = dp[n][i];
			y = i;
		}
	}
	cout<<x<<'\n';
	x = n;
	while (x>0&&y>0){
		vet.push_back(y);
		if (dp[x][y] == dp[x-1][y+1] + a[x][y]) ++y;
		else if (dp[x][y] == dp[x-1][y-1] + a[x][y]) --y;
		--x;
	}
	for (int i = vet.size()-1;i>=0;i--) cout<<vet[i]<<'\n';
	return 0;
}
