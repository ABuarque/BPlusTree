#include "Node.h"
#include <vector>
#include <string>
#include "utils.h"

using namespace std;

Node::Node(Node* root) {
	this->root = root;
}

Node::~Node() {}

int Node::keysSize() {
	return keys.size();
}

string Node::toString() {
	string keysState = "[ ";
	for(int i = 0; i < keys.size(); i++) { 
		keysState += intToString(keys[i]);
		if((i + 1) < keys.size())
			keysState += ", ";
	}
	keysState += " ]";
	return keysState;
}

int Node::binarySearch(std::vector<long> v, long key) {
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
