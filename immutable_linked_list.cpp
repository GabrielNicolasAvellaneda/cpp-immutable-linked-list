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
			Node *head = NULL;
			for (int i = n-1; i >= 0; i--) {
				Node node;
				node.value = values[i];
				if (head != NULL) {
					node.next(head);
					head = &node;
				} else {
					head = &node;
				}
			}
			List* list = new List();
			(*list).head(head);
			return list;
		}

		Node* _head;

		void head(Node* head) {
			this->_head = head;
		}

		int head() {
			return this->_head->value;
		}
};

int main() {

	int numbers[] = {1, 2, 3, 4, 5};
	List *list = List::create(numbers, 5);
	int head = list->head();
	cout << "Head value: " << head << endl;

	return 0;
}
