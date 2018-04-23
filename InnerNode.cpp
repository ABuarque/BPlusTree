#include "InnerNode.h"
#include "Node.h"
#include <vector>
#include <string>

using namespace std;
/*
InnerNode::InnerNode() {
	this->keys = vector<long>();
	this->children = vector<Node*>();
}

InnerNode::~InnerNode() {}

SequenceSet* InnerNode::getSequenceSet(long key) {
	return getChild(key)->getSequenceSet(key);
}

void InnerNode::deleteSequenceSet(long key) {
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
		if(ro)
	}
}

void InnerNode::insertSequenceSet(long key, SequenceSet* sequenceSet) {}

SequenceSet* InnerNode::getFirstLeafKey() {
	return NULL;
}

std::vector<SequenceSet*> InnerNode::getRange(long key1, RangePolicy policy1, 
								   long key2, RangePolicy policy2) {
	vector<SequenceSet*> v;
	return v;
}

void InnerNode::merge(Node* sibilingNode) {}

Node* InnerNode::split() {
	return NULL;
}

bool InnerNode::isOverFlow() {
	return false;
}

bool InnerNode::isUnderFlow() {
	return false;
}

Node* InnerNode::getChild(long key) {
	int index = binarySearch(keys, key);
	int childIndex = index >= 0 ? index + 1 : -index - 1;
	return children[childIndex];
}

void InnerNode::deleteChild(long key) {
	int index = binarySearch(keys, key);
	if(index >= 0) {
		keys.erase(keys.begin() + index);
		children.erase(children.begin() + (index + 1));
	}	
}

void InnerNode::insertChild(long key, Node* child) {
	int index = binarySearch(keys, key);
	int childIndex = index >= 0 ? index + 1 : -index - 1;
    if (index >= 0) {
    	children[childIndex] = child;
    } else {
        keys[childIndex] = key;
        children[childIndex + 1] = child;
    }
}

Node* InnerNode::getChildLeftSibling(long key) {
	int index = binarySearch(keys, key);
	int childIndex = index >= 0 ? index + 1 : -index - 1;
    if (childIndex > 0)
        return children[childIndex - 1];
    return NULL;
}

Node* InnerNode::getChildRightSibling(long key) {
	int index = binarySearch(keys, key);
	int childIndex = index >= 0 ? index + 1 : -index - 1;
    if (childIndex < keysSize())
        return children[childIndex + 1];
    return NULL;	
}

int InnerNode::binarySearch(vector<long> v, long key) {
	int low = 0;
	int top = v.size();
	int mid = (low + top) / 2;

	while(low <= top) {
		if(v[mid] == key)
			return mid;
		else if(v[mid] < key)
			low = mid + 1;
		else
			top = mid - 1;
	}
	return -1;
}
*/
