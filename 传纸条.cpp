#include <bits/stdc++.h>
using namespace std;
int n,m,mam=0;
int s2[52][52];
int dp[52][52];
int f1(int i,int j){
	if(i<1||j<1) return 0;
	if(dp[i-1][j]){
		if(dp[i][j-1]){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+s2[i][j];
			return dp[i][j];
		}
		else{
			dp[i][j]=max(dp[i-1][j],f1(i,j-1))+s2[i][j];
			return dp[i][j];
		}
	}
	else{
		if(dp[i][j-1]){
			dp[i][j]=max(f1(i-1,j),dp[i][j-1])+s2[i][j];
			return dp[i][j]; 
		}
		else{
			dp[i][j]=max(f1(i-1,j),f1(i,j-1))+s2[i][j];
			return dp[i][j];
		}
	}
}

void f3(){
	for(int i=1;i<51;i++)
		for(int j=1;j<51;j++)
			dp[i][j]=0;
	return;
}

void f2(int i,int j,int v){
	int a=s2[i][j];
	s2[i][j]=0;
	if(i<1||j<1) return;
	if(i==1&&j==1){
		mam=max(mam,a+v+f1(n+1,m+1));
		f3();
	}
	f2(i-1,j,a+v);
	f2(i,j-1,a+v);
	s2[i][j]=a;
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>s2[i][j];
	f2(n+1,m+1,0);
	cout<<mam;
	return 0;
}
