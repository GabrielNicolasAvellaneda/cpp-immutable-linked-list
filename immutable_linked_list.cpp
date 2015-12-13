#include <iostream>
#include <cstddef>
using namespace std;

struct Node {
	int value;
	Node* _next = NULL;

	Node next() {
		return (*_next);
	}

	Node next(Node* node) {
		_next = node;
		return next();
	}	
};

int main() {

	Node node1, node2, node3;
	node1.value = 1;
	node1.next(&node2);
	node2.value = 2;
	node3.value = 3;
	node2.next(&node3);

	cout << node1.value << " " << node2.value << " " << node1.next().value << " " << node1.next().next().value << endl;

	return 0;
}
