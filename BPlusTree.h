#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <vector>
#include <string>
#include "SequenceSet.h"
#include "utils.h"
#include "Node.h"

using namespace std;

const int DEFAULT_ODER_FACTOR = 10;

class BPlusTree {
private:
	int orderFactor;

	/*
	class Node {
	protected:
		std::vector<long> keys;

	public:

		Node();

		virtual ~Node();

		int keysSize() {
			return keys.size();
		}

		virtual SequenceSet* getSequenceSet(long key) = 0;

		virtual void deleteSequenceSet(long key) = 0;

		virtual void insertSequenceSet(long key, SequenceSet* sequenceSet) = 0;

		virtual SequenceSet* getFirstLeafKey() = 0;

		virtual std::vector<SequenceSet*> getRange(long key1, RangePolicy policy1, 
										   long key2, RangePolicy policy2) = 0;	

		virtual void merge(Node* sibilingNode) = 0;

		virtual Node* split() = 0;

		virtual bool isOverFlow() = 0;

		virtual bool isUnderFlow() = 0;

		std::string toString() {
			std::string keysState = "[ ";
			for(long i = 0; i < keys.size(); i++) { 
				keysState += intToString(keys[i]);
				if((i + 1) < keys.size())
					keysState += ", ";
			}
			keysState += " ]";
			return keysState;
		}
	};
		
	class InnerNode : Node {
	protected:
		std::vector<Noednes*> children;

		int binarySearch(std::vector<long> v, long key);

	public:

		InnerNode() {
			this->keys = vector<long>();
			this->children = vector<Node*>();
		}

		~InnerNode() {}

		SequenceSet* getSequenceSet(long key) {
			return getChild(key)->getSequenceSet(key);
		}

		void deleteSequenceSet(long key) {
			Node* child = getChild(key);
			child->deleteChild(key);
			if(child->isUnderFlow()) {
				Node* childLeftSibling = getChildLeftSibling(key);
				Node* childRighttSibling = getChildRightSibling(key);
				Node* left = childLeftSibling != NULL ? childLeftSibling : child;
				Node* right = childLeftSibling != NULL ? child : childRighttSibling;
				left->merge(right);
				deleteChild(right->getFirstLeafKey());
				if(left->isOverFlow()) {
					Node* sibling = left->split();
					insertChild(sibling->getFirstLeafKey(), sibling);
				} 
				//if(root->keysSize() == 0)
				//	root = left;
			}
		}

		void insertSequenceSet(long key, SequenceSet* sequenceSet);

		SequenceSet* getFirstLeafKey();

		std::vector<SequenceSet*> getRange(long key1, RangePolicy policy1, 
										   long key2, RangePolicy policy2);	

		void merge(Node* sibilingNode);

		Node* split();

		bool isOverFlow();

		bool isUnderFlow();

		Node* getChild(long key);

		void deleteChild(long key);

		void insertChild(long key, Node* child);

		Node* getChildLeftSibling(long key);

		Node* getChildRightSibling(long key);

	}; */

	Node* root;

	public:
		BPlusTree() {
			this->orderFactor = DEFAULT_ODER_FACTOR;
		}

		BPlusTree(int orderFactor);
		
		~BPlusTree() {}

		std::string toString();
	};

#endif
