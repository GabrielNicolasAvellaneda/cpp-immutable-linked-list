#include <iostream>
#include <cstddef>
#include <vector>

#define NO_SUCH_ELEMENT_EXCEPTION 10;

using namespace std;

class List {
	struct Node {
		int value;
		Node* _next = NULL;

		Node* next(Node* node) {
			_next = node;
			return _next;
		}	
	};

	public:
		static List* create(vector<int> values) {
			List* list = new List();
			for (auto it = values.rbegin(); it != values.rend(); it++) {
				list->insert(*it);
			}
			return list;
		}

		List* insert(int value) {
			Node *node = new Node;
			node->value = value;
			if (!isEmpty()) {
				node->_next = _head;
			}	

			_head = node;
		}

		Node* _head;

		List() {
			_head = NULL;
		}

		int head() {
			if (isEmpty()) {
				throw NO_SUCH_ELEMENT_EXCEPTION;
			}

			return _head->value;
		}

		List* tail() {
			List* list = new List();
			Node* tailHead = this->_head->_next;
			list->_head = tailHead;
			return list;
		}

		bool isEmpty() {
			return _head == NULL;
		}

};

int main() {

	vector<int> numbers = {1, 2, 3, 4, 5};
	List *list = List::create(numbers);
	int head = list->head();
	List *tail = list->tail();
	cout << "Head value: " << head << endl;
	
	try {
		int tailHead = tail->head();
		cout << "Tail head: " << tailHead << endl;
	}
	catch (int e) {
		cout << "Exception thrown: "  << e << endl;
	}
	return 0;
}
