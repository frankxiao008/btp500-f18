template <class T>
class Queue{
	T* theQueue_;
	int capacity_;
	int used_;
	int front_;
	int back_;
	void grow(){
		T* tmp=new T[capacity_*2];
		int j=front_;
		for(int i=0;i<used_;i++){
			tmp[i]=theQueue_[j];
			j=(j+1)%capacity_;
		}
		capacity_=capacity_*2;
		delete []  theQueue_;
		theQueue_=tmp;
		front_=0;
		back_=used_;		
	}
public:
	Queue(){
		theQueue_=new T[13];
		capacity_=13;
		used_=0;
		front_=0;
		back_=0;
	}
	void enqueue(const T& data){
		if(used_==capacity_){
			grow();
		}

		theQueue_[back_]=data;
		back_=(back_+1)%capacity;
/*		theQueue_[back_++]=data;
		if(back_==capacity_)
			back_=0;*/
		used_++;
	}
	void dequeue(){
		if(used_!=0){
			front_=(front_+1)%capacity_;
/*			front_++;
			if(front_==capacity_){
				front_=0;
			}*/
			used_--;
		}
	}
	T front() const{

	}
	bool isEmpty() const{
	}
	~Queue(){
		delete [] theQueue_;
	}	
};