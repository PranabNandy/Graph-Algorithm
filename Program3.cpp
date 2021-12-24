/* 
..... g++ -std=c++11 Test.c++ -lpthread   ....
*/


/*
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

*/

#include<bits/stdc++.h>
using namespace std;


int c=1;
mutex m;
condition_variable cond;
void even(){
	 std::thread::id this_id = std::this_thread::get_id();
	unique_lock<mutex> l1(m,defer_lock);
	 while(1)
   {
       l1.lock();
       //if(c>INT_MAX-10)
       //    break;
       cond.wait(l1,[]{ return (c%2==0)?true:false; });
        cout<<this_id<<"  I am Even "<<c<<endl;
        c++;
     
       
       l1.unlock();
       cond.notify_all();
   }
}
void odd(){
	std::thread::id this_id = std::this_thread::get_id();
	unique_lock<mutex> l2(m,defer_lock);
	while(1)
    {
    	//if(c>INT_MAX-10)
         // break;
       l2.lock();
       cond.wait(l2,[]{ return (c%2==1)?true:false; });
       
   
       cout<<this_id<<"   I am odd "<<c<<endl;
       c++;
       
       l2.unlock();
       cond.notify_all();
    }

}
int main(){
	
	
	//thread t1(even);
	//thread t2(odd);
	for(;;){
		thread *t1=new thread(even);
		thread *t2=new thread(odd);

		t1->join();
		t2->join();
	}
	
	
	//this_thread::sleep_for(chrono::seconds(2));
	return 0;
}