template <class T>
class Queue{
	T* theQueue_;
	int capacity_;
	int used_;
	void grow(){
	}
public:
	Queue(){
		theQueue_=new T[13];
		capacity_=13;
		used_=0;
	}
	void enqueue(const T& data){
		if(used_==capacity_){
			grow();
		}
		
	}
	void dequeue(){
	}
	T front() const{

	}
	bool isEmpty() const{
	}
	~Queue(){
		delete [] theQueue_;
	}	
};