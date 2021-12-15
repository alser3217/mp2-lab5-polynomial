#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <fstream>

template<typename T>
class List;

template<typename T>
class Node {
	T data;
	Node* pNext = nullptr;
public:
  Node(T _data = T()) : data(_data) {}
	friend std::ostream& operator<<(std::ostream& os, const Node& node) {
		os << node.data;
		return os;
	}
	friend std::ostream& operator<<(std::ostream& os, const List<T>& list);
	friend class List<T>;
	Node(const Node& object);
};

template<typename T>
Node<T>::Node(const Node& object) {
	data = object.data;
	pNext = nullptr;
}

template<typename T>
class List {
	Node<T>* pHead = nullptr;
	int Size = 0;
public:
	List() {}
	~List();
	bool is_empty();
	void push_back(T data);
	T& operator[] (const int index) const;
	void remove(const int index);
	void clear();
	int size();
	void swap(const int l);
	List<T>& operator=(const List<T>& object);

	friend std::ostream& operator<<(std::ostream& os, const List& list) {
		Node<T>* current_node = list.pHead;
		while (current_node->pNext != nullptr) {
			os << *current_node << " ";
			current_node = current_node->pNext;
		} 
		os << *current_node << " ";
		return os;
	}
};


template<typename T>
List<T>::~List<T>() {
	clear();
}

template<typename T>
bool List<T>::is_empty() {
	return pHead == nullptr;
}

template<typename T>
void List<T>::push_back(T data) {
	if (is_empty()) {
		pHead = new Node<T>(data);
	}
	else {
		Node<T>* current_node = pHead;
		while (current_node->pNext != nullptr) {
			current_node = current_node->pNext;
		}
		current_node->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index) const{
	Node<T>* current_node = pHead;
	for (int i = 0; i < index; i++) {
		current_node = current_node->pNext;
	}
	return current_node->data;
}

template<typename T>
void List<T>::remove(const int index) {
	Node<T>* node_to_delete;
	Node<T>* previous_node = pHead;
	if (index == 0) {
		node_to_delete = pHead;
		pHead = pHead->pNext;
		delete node_to_delete;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			previous_node = previous_node->pNext;
		}
		node_to_delete = previous_node->pNext;
		previous_node->pNext = node_to_delete->pNext;
		delete node_to_delete;
	}
	Size--;
}

template<typename T>
void List<T>::clear() {
	if (!is_empty()) {
		Node<T>* current_node = pHead->pNext;
		Node<T>* node_to_delete = pHead;
		while (current_node != nullptr) {
			delete node_to_delete;
			node_to_delete = current_node;
			current_node = current_node->pNext;
		}
		delete node_to_delete;
		pHead = nullptr;
		Size = 0;
	}
}

template<typename T>
int List<T>::size() {
	return Size;
}

template<typename T>
void List<T>::swap(const int l) {
	Node<T>* tmp1;
	Node<T>* tmp2;
	Node<T>* tmp3;
	Node<T>* current_node = pHead;
	if (l == 0) {
		tmp1 = pHead;
		tmp2 = tmp1->pNext;
		tmp3 = tmp2->pNext;
		pHead = tmp2;
		tmp2->pNext = tmp1;
		tmp1->pNext = tmp3;
	}
	else {
		for (int i = 0; i < l - 1; i++) {
			current_node = current_node->pNext;
		}
		tmp1 = current_node->pNext;
		tmp2 = tmp1->pNext;
		tmp3 = tmp2->pNext;
		current_node->pNext = tmp2;
		tmp2->pNext = tmp1;
		tmp1->pNext = tmp3;
	}
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& object) {
	if (this == &object)
		return *this;
	if (object.Size == 0)
		return *this;
	Node<T>* current_node = object.pHead;
	Node<T>* new_node;
	clear();
	Size = object.Size;
	pHead = new Node<T>(object.pHead->data);
	new_node = pHead;
	while (current_node->pNext != nullptr) {
		new_node->pNext = new Node<T>(current_node->pNext->data);
		new_node = new_node->pNext;
		current_node = current_node->pNext;
	} 
	return *this;
}

#endif
