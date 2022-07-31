#pragma once

template <typename T>
priority_queue<T>& priority_queue<T>::operator=(const priority_queue<T>& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	
	if (vec.size() > rhs.vec.size())
	{
		for (int i = 0;i < vec.size();++i)
		{
			pop();
			if (vec.size() == rhs.vec.size()) {
				break;
			}
		}
	}

	for (int i = 0;i < rhs.size(); ++i)
	{
		vec[i] = rhs.vec[i];
	}

	return *this;
}

template <typename T>
priority_queue<T>& priority_queue<T>::operator=(priority_queue<T>&& rhs)
{
	if (!empty()) {
		vec.clear();
	}
	vec = rhs.vec;
	return *this;
}

template <typename T>
T priority_queue<T>::parent(T i) {
	return (i - 1) / 2;
}

template <typename T>
T priority_queue<T>::left_child(T i) {
	return (2 * i + 1);
}

template <typename T>
T priority_queue<T>::right_child(T i) {
	return (2 * i + 2);
}

template <typename T>
size_t priority_queue<T>::size() const
{
	size_t count = 0;
	for (int i = 0;i < vec.size();++i)
	{
		++count;
	}
	return count;
}

template <typename T>
void priority_queue<T>::heapify_down(T i)
{
	int largest = i;
	int left = left_child(i);
	int right = right_child(i);

	if (left < size() && vec[left] > vec[i]) {
		largest = left;
	}

	if (right<size() && vec[right] > vec[largest]) {
		largest = right;
	}

	if (largest != i)
	{
		std::swap(vec[i], vec[largest]);
		heapify_down(largest);
	}
}

template <typename T>
void priority_queue<T>::heapify_up(T i)
{
	if (i && vec[parent(i)] < vec[i])
	{
		std::swap(vec[i], vec[parent(i)]);
		heapify_up(parent(i));
	}
}

template <typename T>
const T& priority_queue<T>::top() const 
{
	if (size() == 0) {
		throw std::out_of_range("");
	}
	return vec[0];
}

template <typename T>
bool priority_queue<T>::empty() const {
	return size() == 0;
}

template <typename T>
void priority_queue<T>::push(const T& val)
{
	vec.push_back(val);
	int index = size() - 1;
	heapify_up(index);
}

template <typename T>
void priority_queue<T>::push(T&& val)
{
	vec.push_back(std::move(val));
	int index = size() - 1;
	heapify_up(index);
}

template <typename T>
void priority_queue<T>::pop()
{
	if (size() == 0) {
		throw std::out_of_range("");
	}
	vec[0] = vec.back();
	vec.pop_back();
	heapify_down(0);
}

template <typename T>
void priority_queue<T>::swap(priority_queue& obj) noexcept
{
	std::vector<T> vec2 = vec;
	vec = obj.vec;
	obj.vec = vec2;
}

template <typename T>
void priority_queue<T>::print() const
{
	for (int i = 0;i < vec.size();++i)
	{
		std::cout << vec[i] << "  ";
	}
}