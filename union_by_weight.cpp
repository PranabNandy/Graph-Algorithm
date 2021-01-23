#include<bits/stdc++.h>

using namespace std;
vector<int> arr;


void make_set(int p){
	arr[p]=-1;
}

//find by path compression
int find(int a){
	if(arr[a]<0){
		return a;
	}

	int b=find(arr[a]);
	arr[a]=b;
	return b;
}

//union_by_weight
int Union(int a,int b){
	int c=find(a);
	int d=find(b);

	if(c==d){
		return 1;

	}
	int c1=arr[c],d1=arr[d];
	int c2=abs(c1),d2=abs(d1);
	//cout<<"c "<<c<<"d "<<d<<endl;
	if((c2>=d2)){
		arr[c]=arr[c]+arr[d];
		arr[d]=c;
	}
	else{
		arr[d]=arr[c]+arr[d];
		arr[c]=d;

	}

	return 0;

}
int main(){


	int n=8;
	arr.resize(n+1);

	for(int i=1;i<=n;i++)
		make_set(i);


	cout<<"First "<<find(5)<<endl;
	cout<<"First "<<find(2)<<endl;

	for(int i=1;i<=15;i++){
		int first,second;
		cin>>first>>second;
		if(Union(first,second))
			cout<<"<----- Forms a Loop ------>"<<endl;
		for(int i:arr) cout<<i<<" "; cout<<endl;
	}
	/*Union(1,2);
	Union(3,4);
	Union(5,6);
	Union(7,8);

for(int i:arr) cout<<i<<" "; cout<<endl;


	cout<<"Second "<<find(5)<<endl;

	cout<<"Second "<<find(2)<<endl;


	Union(2,4);
	Union(5,2);
	Union(8,3);


for(int i:arr) cout<<i<<" "; cout<<endl;


	cout<<"Third "<<find(6)<<endl;
	cout<<"Third "<<find(8)<<endl;


for(int i:arr) cout<<i<<" "; cout<<endl;*/
	return 0;

}