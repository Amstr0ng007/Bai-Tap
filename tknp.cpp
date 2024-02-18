#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int a[N];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,h;cin>>n>>h;
		for (int i =1;i<=n;i++){
			int x;cin>>x;
			a[i] = x+a[i-1];
		}
//		cout<<a[0];
//		for (int i =1;i<=n;i++) cout<<a[i]<<' ';
//		cout<<'\n';
		int l=1,hi=n,m,kq=-1;
		while (l<=hi){
			m = l+(hi-l)/2;
			if (a[m]==h) {
//				cout<<m;
				break;
			}
			else if (a[m]>h) hi = m-1;
			else l = m+1;
		}
		if (a[m]==h) cout<<m<<'\n';
		else  cout<<l-1<<'\n';
	}
	return 0;
}
