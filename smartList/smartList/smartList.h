#pragma once

#ifndef  SmartList_H_
#define SmartList_H_

#define RESIZE 5

#define ERROR_NOELEMENTS 0

template <class T>
class TNode
{
public:
	T _data;
	TNode* _next = nullptr;
private:
};

template <class T>
class MemoryStack
{
public:
	MemoryStack() {}
	~MemoryStack();

	void addMemory(size_t value);
	TNode<T>*& pop_memory();
	void push_memory(TNode<T>*& node);
private:
	TNode<T>* _top = nullptr;
	size_t _size = 0;

	void addSingle();
};

template <class T>
class SmartList
{
public:
	SmartList() {}
	~SmartList();

	void push_back(T data);
	T    pop_back();
	bool empty();
private:
	MemoryStack<T> buffer;
	TNode<T>* _first = nullptr;
	size_t _size = 0;
};

//////////////////////////////////////////////////////

template<class T>
inline MemoryStack<T>::~MemoryStack()
{
	TNode<T>* currNode;
	while (this->_top != nullptr)
	{
		currNode = this->_top->_next;
		delete this->_top;
		this->_top = currNode;
	}
}

template<class T>
inline void MemoryStack<T>::addMemory(size_t value)
{
	for (size_t i = 0; i < value; i++)
	{
		addSingle();
	}
}

template<class T>
inline void MemoryStack<T>::addSingle()
{
	TNode<T>* tmpNode = new TNode<T>;
	tmpNode->_next = this->_top;
	this->_top = tmpNode;
	this->_size++;
}

template<class T>
inline TNode<T>*& MemoryStack<T>::pop_memory()
{
	if (this->_top == nullptr)
		addMemory(RESIZE);
	TNode<T>* currNode = this->_top;
	this->_top = this->_top->_next;
	this->_size--;
	return currNode;
}

template<class T>
inline void MemoryStack<T>::push_memory(TNode<T>*& node)
{
	node->_next = this->_top;
	this->_top = node;
	this->_size++;
}

template<class T>
inline SmartList<T>::~SmartList()
{
	while (this->_first != nullptr)
	{
		pop_back();
	}
	this->buffer.~MemoryStack();
}

template<class T>
inline void SmartList<T>::push_back(T data)
{
	TNode<T>* tmpNode = this->buffer.pop_memory();
	tmpNode->_data = data;
	tmpNode->_next = this->_first;
	this->_first = tmpNode;
	this->_size++;
}

template<class T>
inline T SmartList<T>::pop_back()
{
	if (empty())
		exit(ERROR_NOELEMENTS);
	T res = this->_first->_data;
	TNode<T>* tmpNode = this->_first;
	this->_first = this->_first->_next;
	this->buffer.push_memory(tmpNode);
	
	this->_size--;
	return res;
}

template<class T>
inline bool SmartList<T>::empty()
{
	return (this->_first == nullptr);
}

#endif // ! SmartList_H_