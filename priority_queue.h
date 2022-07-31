#pragma once
#include <vector>

template <typename T>
class priority_queue
{
public:
	priority_queue() = default;
	priority_queue& operator=(const priority_queue&);
	priority_queue& operator=(priority_queue&&);
	~priority_queue() { vec.clear(); }

public:
	const T& top() const;
	bool empty() const;
	size_t size() const;
	void push(const T&);
	void push(T&&);
	void pop();
	void swap(priority_queue&) noexcept;
	void print() const;

private:
	std::vector<T> vec;

private:
	T parent(T);
	T left_child(T);
	T right_child(T);
	void heapify_down(T);
	void heapify_up(T);
};






#include "priority_queue.hpp"