#pragma once
#include "list.h"
#include <iostream>

template<typename T>
class Queue
{
public:

	Queue() {};

	Queue(Queue<T>& one) { // copy constructor

		for (int i = 0; i < one.order.get_length(); ++i){
			this->push(one.order[i]);
		}
	};

	~Queue() {

		this->clean();
	};

	void push(T one) {

		this->order.push_back(one);
		this->size++;
	}

	void pop() {

		if (this->size == 0) {
			throw std::out_of_range("Out of range");
		}
		this->order.pop_front();
		this->size--;
	}

	int get_size() {
		return this->size;
	}

	void front() const {

		return this->order.front();
	}

	bool is_empty() const {

		bool flag;
		this->size == 0 ? flag = true : flag = false;
		return flag;
	}

	void print_all() {

		this->order.print_all();
	}
	void clean() {

		this->order.clear();
		size = 0;
	}

private:

	List<T> order;
	int size = 0;
};

