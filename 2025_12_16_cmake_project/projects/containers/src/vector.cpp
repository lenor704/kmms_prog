#include "vector.hpp"

#include <iostream>

using ule::Vector;

template<typename T>
const std::size_t Vector<T>::START_CAPACITY = 1;

template<typename T>
Vector<T>::Vector() {
	capacity = START_CAPACITY;
	size = 0;
	arr = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
	size = 0;
	delete[] arr;
	arr = nullptr;
	capacity = 0;
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
	return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
	for (std::size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return true;
		}
	}
	return false;		
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (position > size) {
		return false;
	}
	size++;
	if (capacity <= size) {
		capacity *= 2;		
		T* new_arr = new T[capacity];
		
		for (std::size_t i = size; i > position; i--) {
			new_arr[i] = arr[i - 1];
		}
		new_arr[position] = value;
		for (std::size_t i = 0; i < position; i++) {
			new_arr[i] = arr[i];
		}
		
		delete[] arr;
		arr = new_arr;	
		return true;		
	}
	
	for (std::size_t i = size; i > position; i--) {
		arr[i] = arr[i - 1];
	}
	arr[position] = value;
	return true;
}

template<typename T>
void Vector<T>::print() const noexcept {
	for (std::size_t i = 0; i < size; i++) {
		std::cout << arr[i];
		if (i + 1 < size) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;	
}

template<typename T>
void Vector<T>::push_back(const T& value) {
	size++;
	if (capacity <= size) {
		capacity *= 2;
		change_capacity(capacity);
	}
	
	arr[size - 1] = value;
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {
	bool flag = true;
	for (std::size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			for (int j = i; j < size; j++) {
				arr[j] = arr[j + 1];
			}
			size --;
			if (capacity > size * 2) {
				capacity /= 2;
				change_capacity(capacity);
			}
			return true;
		}
	}
	return false;
}

template<typename T>
void Vector<T>::change_capacity(const std::size_t new_capacity) {
	T* new_arr = new T[new_capacity];
	for (std::size_t i = 0; i < size; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
	capacity = new_capacity;
}

template<typename T>
void Vector<T>::add_capacity_insert(const std::size_t new_capacity, const std::size_t position, const T& value) {

}