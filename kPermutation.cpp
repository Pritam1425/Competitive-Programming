#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> applyPermutation(vector<int>sequence,vector<int>permutation){
	vector<int>result(sequence.size());
	for(int i=0;i<sequence.size();i++){
		result[i] = sequence[permutation[i]];
	}
	return result;
}
vector<int> kPermutation(vector<int>sequence,vector<int>permutation,ll b){
	while(b>0){
		if(b&1){
			sequence = applyPermutation(sequence,permutation);
		}
		permutation = applyPermutation(permutation,permutation);
		b >>= 1;
	}
	return sequence;
}
vector<int> kPermLinear(vector<int>seq,vector<int>perm,ll b){
	vector<vector<int> >result;
	bool visited[seq.size()];
	for(int i=0;i<seq.size();i++){
		visited[i] = false;
	}
	for(int i=0;i<seq.size();i++){
		if(!visited[i]){
			int val = i;
			vector<int>tmp;
			visited[i] = true;
			tmp.push_back(i);
			while(perm[val]!=i){
				tmp.push_back(perm[val]);
				val = perm[val];
				visited[val] = true;
			}
			result.push_back(tmp);
		}
	}
	vector<int>ans(seq.size());
	for(int i=0;i<result.size();i++){
		int n = result[i].size();
		for(int j=0;j<n;j++){
			ans[result[i][j]] = seq[result[i][(j+b%n)%n]];
		}
	}
	return ans;	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[10] = {8,9,0,6,5,2,7,3,4,1};
	vector<int>seq,perm(arr,arr+10);
	for(int i=0;i<10;i++){
		seq.push_back(i+1);
	}
	vector<int>newSeq = kPermutation(seq,perm,127);
	for(int i=0;i<10;i++){
		cout<<newSeq[i]<<" ";
	}
	cout<<"\n";
	vector<int>nSeq = kPermLinear(seq,perm,127);
	for(int i=0;i<10;i++){
		cout<<nSeq[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
