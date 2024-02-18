#include <bits/stdc++.h>
using namespace std;
int dp[102][102];
vector <char> v;
vector <int> xd;
vector <int> dx;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("inp.inp","r",stdin);
	freopen("inp.out","w",stdout);
	string a,b;cin>>a>>b;
	a = ' '	+ a;
	b = ' ' + b;
	int x = a.size()-1,y = b.size()-1;
	for (int i =1;i<=x;i++)
		for (int j = 1;j<=y;j++){
			if (a[i]==b[j]) dp[i][j] =dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	int i = x,j = y;
	while (i>0 && j>0){
		if (a[i] == b[j]){
			v.push_back(a[i]);
			xd.push_back(i);
			dx.push_back(j);
			--i;--j;
		}
		else if(dp[i][j] == dp[i-1][j]) --i;
		else --j;
	}
	for (int i = v.size()-1;i>=0;i--) cout<<v[i];
	cout<<'\n';
	for (int i = xd.size()-1;i>=0;i--) cout<<xd[i]<<' ';
	cout<<'\n';
	for (int i = dx.size()-1;i>=0;i--) cout<<dx[i]<<' ';
	return 0;
}