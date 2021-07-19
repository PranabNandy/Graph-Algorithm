/* 
..... g++ -std=c++11 Test.c++ -lpthread   ....
*/

#include<bits/stdc++.h>
using namespace std;


mutex mu;
condition_variable cond;
deque<string> item;
vector<string> v;
void producer(){
	unique_lock<mutex> l1(mu,defer_lock);
	for(int i=0;i<100;i++){
		l1.lock();
		string x=v.back();
		v.pop_back();
		item.push_back(x);
		cout<<".....Producer has successfully produced the item ......"<<x<<endl;
		l1.unlock();
		cond.notify_all();
	}


}
void consumer(){
	unique_lock<mutex> l1(mu,defer_lock);
	l1.lock();
	for(int i=0;i<100;i++){
		
		cond.wait(l1,[]{ return (item.size()>0)?true:false; });
		
		string x="Nothing ";
		if(item.size()){
			x=item.front();
			item.pop_front();
		}
		cout<<"Consumer has successfully consumed the item    >>>>   "<<x<<endl;
		//l1.unlock();
	}

}
int main(){
	v.resize(100);
	for(int i=0;i<100;i++){
		string x;
		x+=to_string(i);
		v[i]=x;
	};
	this_thread::sleep_for(chrono::seconds(2));
	thread t1(producer);
	thread t2(consumer);

	t1.join();
	t2.join();
	cout<<"Size of item : "<<item.size()<<endl;
	return 0;
}
