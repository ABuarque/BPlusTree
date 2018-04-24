#ifndef INNERNODE_H
#define INNERNODE_H

#include "Node.h"
#include "SequenceSet.h"
#include <vector>

using namespace std;

class InnerNode : Node {
protected:
	std::vector<Node*> children;

	int binarySearch(std::vector<long> v, long key);

public:

	InnerNode(Node* root) : Node(root) {
		this->keys = std::vector<long>();
		this->children = std::vector<Node*>();
	}

	InnerNode() : Node(NULL) {
		this->keys = std::vector<long>();
		this->children = std::vector<Node*>();	
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
			if(root->keysSize() == 0)
				root = left;
		}
	}

	void insertSequenceSet(long key, 
									  SequenceSet* sequenceSet) {
		Node* child = getChild(key);
		child->insertSequenceSet(key, sequenceSet);
		if(child->isOverFlow()) {
			Node* sibiling = child->split();
			insertChild(sibiling->getFirstLeafKey(), sibiling);
		}
		if(root->isOverFlow()) {
			Node* sibiling = split();
			InnerNode* newRoot = new InnerNode();
			newRoot->keys.push_back(sibiling->getFirstLeafKey());
			newRoot->children.push_back(this);
			newRoot->children.push_back(sibiling);
			root = newRoot;
		}
	}

	long getFirstLeafKey() {
		return children[0]->getFirstLeafKey();
	}

	std::vector<SequenceSet*> getRange(long key1, RangePolicy policy1, 
									   long key2, RangePolicy policy2) {
		return getChild(key1)->getRange(key1, policy1, key2, policy2);
	}

	void merge(Node* sibilingNode) {}

	Node* split() {
		return NULL;
	}

	bool isOverFlow() {
		return false;
	}

	bool isUnderFlow() {
		return false;
	}

	Node* getChild(long key) {
		int index = binarySearch(keys, key);
		int childIndex = index >= 0 ? index + 1 : -index - 1;
		return children[childIndex];
	}

	void deleteChild(long key) {
		int index = binarySearch(keys, key);
		if(index >= 0) {
			keys.erase(keys.begin() + index);
			children.erase(children.begin() + (index + 1));
		}	
	}

	void insertChild(long key, Node* child) {
		int index = binarySearch(keys, key);
		int childIndex = index >= 0 ? index + 1 : -index - 1;
	    if (index >= 0) {
	    	children[childIndex] = child;
	    } else {
	        keys[childIndex] = key;
	        children[childIndex + 1] = child;
	    }
	}

	Node* getChildLeftSibling(long key) {
		int index = binarySearch(keys, key);
		int childIndex = index >= 0 ? index + 1 : -index - 1;
	    if (childIndex > 0)
	        return children[childIndex - 1];
	    return NULL;
	}

	Node* getChildRightSibling(long key) {
		int index = binarySearch(keys, key);
		int childIndex = index >= 0 ? index + 1 : -index - 1;
	    if (childIndex < keysSize())
	        return children[childIndex + 1];
	    return NULL;	
	}
};

#endif

