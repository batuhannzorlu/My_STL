#pragma once

template<typename T>
class bz_stack {

	
public:
	 bz_stack();

	void pop();
	T top();
	inline bool empty();
	//int size();
	void push(T val);
	//void emplace();
	//void swap();

	~bz_stack();

private:
	T* arr;
	int size=2;
	int curr_pos=0;
};

template<typename T>
bz_stack<T>::bz_stack(){

	this->arr = new T[size];

}

template<typename T>
void bz_stack<T>::pop() {
	if (!this->empty())
		this->curr_pos-=1;
	else throw std::range_error("stack is already empty!");  }

template<typename T>
T bz_stack<T>::top() {
	if (!this->empty())
		return this->arr[this->curr_pos-1];
	else throw std::range_error("stack is empty!");
}
template<typename T>
inline bool bz_stack<T>::empty() { return this->curr_pos+1 == 0 ? true : false; }

template<typename T>
void bz_stack<T>::push(T val) { 
	
	if (curr_pos > size-2) {
		this->size *= 2;
		T* t_arr = new T[this->size];

		for(int i=0 ; i< curr_pos;i++)
			t_arr[i] = this->arr[i];

		delete[] arr;
		arr = t_arr;
	}
	this->arr[curr_pos] = val; 
	this->curr_pos++; 


}


template<typename T>
bz_stack<T>::~bz_stack(){}