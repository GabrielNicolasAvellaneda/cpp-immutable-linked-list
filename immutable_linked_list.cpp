#include <iostream>
#include <cstddef>
using namespace std;

struct Node {
	int value;
	Node* next = NULL;
};

int main() {

	Node node1, node2;
	node1.value = 1;
	node1.next = (Node*)&node2;
	node2.value = 2;

	cout << node1.value << " " << node2.value << " " << (*node1.next).value;

	return 0;
}
