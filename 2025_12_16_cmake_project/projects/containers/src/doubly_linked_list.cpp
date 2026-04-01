#include "doubly_linked_list.hpp"

#include <iostream>

using ule::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	Node* current = begin;
	while (current != nullptr) {
		begin = current->next;
		delete current;
		current = current->next;
	}
	begin = nullptr;
	end = nullptr;
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
	Node* current = begin;
	std::size_t size = 0;
	for (current; current != 0; current = current->next) {
		size++;
	}
	return size;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
	Node* current = begin;
	for (current; current != nullptr; current = current->next) {
		if (current->value == value) {
			return true;
		}
	}
	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	Node* current = begin;
	for (current; current != nullptr; current = current->next) {
		std::cout << current->value;
		if (current->next != nullptr) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	Node* current = new Node(value);
	current->value = value;
	current->prev = end;
	current->next = nullptr;
	
	if (end != nullptr) {
		end->next = current;
	}
	if (begin == end && begin == nullptr) {
		begin = end = current;
	} else {
		end = current;
	}
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	Node* current = begin;
	for (current; current != nullptr; current = current->next) {
		if (current->value == value) {
			if (current->next != nullptr && current->prev != nullptr) {
				current->prev->next = current->next;
				current->next->prev = current->prev;
			} else if (current->next == nullptr){
				current->prev->next = nullptr;
				end = current->prev;
			} else {
				current->next->prev = nullptr;
				begin = current->next;
			}
			
			delete current;
			return true;
		}
	}
	return false;
}
