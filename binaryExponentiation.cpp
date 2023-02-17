#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Mat22{
	public:
		ll a11,a12,a21,a22;
		Mat22(ll a11=0,ll a12=0,ll a21=0,ll a22=0){
			this->a11 = a11;
			this->a12 = a12;
			this->a21 = a21;
			this->a22 = a22;
		}
		Mat22(Mat22 &obj){
			this->a11 = obj.a11;
			this->a12 = obj.a12;
			this->a21 = obj.a21;
			this->a22 = obj.a22;
		}
		Mat22 operator * (Mat22 const &obj){
			Mat22 res(0,0,0,0);
			res.a11 = a11*obj.a11+a12*obj.a21;
			res.a12 = a11*obj.a12+a12*obj.a22;
			res.a21 = a21*obj.a11+a22*obj.a21;
			res.a22 = a21*obj.a12+a22*obj.a22;
			return res;
		}
		
};
ll binaryExpRec(ll a,ll n){
	if(n==0)
		return 1;
	ll tmp = binaryExpRec(a,n/2);
	if(n%2==0)
		return(tmp*tmp);
	else
		return(a*tmp*tmp);
}
ll binaryExpIter(ll a,ll n){
	ll res = 1;
	while(n){
		if(n&1)
			res *= a;
		a *= a;
		n = n>>1;
	}
	return res;
}
ll binaryExpMod(ll a,ll n,ll m){
	a %= m;
	ll res = 1;
	while(n>0){
		if(n&1==1){
			res = (res*a)%m;
		}
		a = (a*a)%m;
		n = n>>1;
	}
	return res;
}
ll binaryExpMatrix(ll n){
	Mat22 res(1,0,0,1);
	if(n==0||n==1){
		return n;
	}
	Mat22 mat(1,1,1,0);
	while(n>0){
		if(n&1){
			res = res*mat;
		}
		mat = mat*mat;
		n >>= 1;
	}
	return res.a21;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<binaryExpRec(3,13)<<"\n";
	cout<<binaryExpIter(3,13)<<"\n";
	cout<<binaryExpMod(3,13,1e6)<<"\n";
	for(int i=0;i<15;i++)
		cout<<binaryExpMatrix(i)<<"\n";
}
