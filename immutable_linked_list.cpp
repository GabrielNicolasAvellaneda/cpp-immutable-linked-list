#include <iostream>
#include <cstddef>
using namespace std;

class List {
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

	public:
		static List* create(int values[], int n) {
			List* list = new List();
			for (int i = n-1; i >= 0; i--) {
				int value = values[i];
				list->insert(value);
			}
			return list;
		}

		void insert(int value) {
			Node node;
			node.value = value;
			if (_head != NULL) {
				node.next(_head);
			}	

			_head = &node;
		}

		Node* _head;

		List() {
			_head = NULL;
		}

		int head() {
			return _head->value;
		}


};

int main() {

	int numbers[] = {1, 2, 3, 4, 5};
	List *list = List::create(numbers, 5);
	int head = list->head();
	cout << "Head value: " << head << endl;

	return 0;
}
