#ifndef NATIVEMETHODS_H
#define NATIVEMETHODS_H

#include "SequenceSet.h"
#include "Node.h"

using namespace std;

class NativeMethods {
public:
	void sortedInset(long key, SequenceSet* sequenceSet, Node* node) {
		std::list<long> data = node->getKeys();
		std::list<SequenceSet*> pointers = node->getPointers();
		if(data.size() == 0) {
			data.push_back(key);
			pointers.push_back(sequenceSet);
		} else {
			if(key < *(data.begin())) {
				data.push_front(key);
				pointers.push_front(sequenceSet);
			} else {
				bool flag = true;
				for(int i = 0; i < data.size(); i++) {
					long current = *(next(data.begin(), i));
					if(key < current) {
						flag = false;
						data.insert(next(data.begin(), i), key);
						pointers.insert(next(pointers.begin(), i), sequenceSet);
						break;
					}
				}
				if(flag) {
					data.push_back(key);
					pointers.push_back(sequenceSet);
				}
			}
		}
	}

	void sortedInsertInternal(long key, SequenceSet* sequenceSet, Node* node) {
		std::list<long> data = node->getKeys();
		std::list<SequenceSet*> pointers = node->getPointers();
		if(key < *(next(data.begin(), 0))) {
			data.push_front(key);
			pointers.insert(next(pointers.begin(), 1), sequenceSet);
		} else {
			bool flag = true;
			for(int i = 0; i < data.size(); i++) {
				long current = *(next(data.begin(), i));
				if(key < current) {
					data.insert(next(data.begin(), i), key);
					pointers.insert(next(pointers.begin(), (i + 1)), sequenceSet);
					flag = false;
					break;
				}
			}
			if(flag) {
				data.push_back(key);
				pointers.push_back(sequenceSet);
			}
		}
	}

	void deleteNode(Node* node, long key) {
		for(int i = 0; i < node->getKeys().size(); i++) {
			long current = *(next(node->getKeys().begin(), i));
			if(key == current) {
				node->getKeys().erase(next(node->getKeys().begin(), i));
				node->getPointers().erase(next(node->getPointers().begin(), i));
			}
		}
	}

	void internalDelete(long key, Node* node, Node* temp) {
		for(int i = 0; i < node->getKeys().size(); i++) {
			long current = *(next(node->getKeys().begin(), i));
			if(current == key) {
				node->getKeys().erase(next(node->getKeys().begin(), i));
				node->getPointers().erase(next(node->getPointers().begin(), (i + 1)));
			}
		}
	}

	bool sameParent2(Node* parent, Node* node) {
		bool _next = false;
		bool _prev = false;
		Node* next = node->getNext();
		Node* prev = node->getPrev();
		if(next != NULL) {
			for(int i = 0; i < parent->getPointers().size(); i++) {
				if(next == next(parent->getPointers().begin(), i)) {
					_next = true;
					break;
				}
			}
		}
		if(prev != NULL) {
			for(int i = 0; i < parent->getPointers().size(); i++) {
				if(next == next(parent->getPointers().begin(), i)) {
					_prev = true;
					break;
				}
			}
		}
		if(_next) 
			return true;
		else
			return false;
	}

	/*int sameParent(Node* node, Node* parent, int size) {
		list<long> keys = parent->getKeys();
		bool _next = false;
		bool _prev = false;
		Node* next = node->getNext();
		Node* prev = node->getPrev();
		if()
	}*/
};

#endif
