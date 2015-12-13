#include <iostream>
#include <cstddef>
#include <vector>

#define NO_SUCH_ELEMENT_EXCEPTION 10

#define UNSUPPORTED_OPERATION_EXCEPTION 12

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

	protected:
		List(Node* head) {
			_head = head;
		}

	public:
		static int last(List* list) {
			if (list->isEmpty()) {
				throw NO_SUCH_ELEMENT_EXCEPTION;
			}
			
			auto head = list->head();
			auto tail = list->tail();
			if (tail->isEmpty()) {
				return  head;
			}

			return last(tail);
		}

		static List* create(vector<int> values) {
			List* list = new List();
			for (auto it = values.rbegin(); it != values.rend(); it++) {
				list = list->insert(*it);
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
			if (isEmpty()) {
				throw UNSUPPORTED_OPERATION_EXCEPTION;
			}

			Node* tailHead = this->_head->_next;
			List* list = new List(tailHead);
			return list;
		}

		bool isEmpty() {
			return _head == NULL;
		}

		int last() {
			List::last(this);
		}


};

void printList(List* list) {
	if (list->isEmpty())
		return;

	int head = list->head();
	cout << head << endl;
	printList(list->tail());
}

int main() {

	vector<int> numbers = {1, 2, 3, 4, 5};
	List *list = List::create(numbers);
	int head = list->head();
	List *tail = list->tail();

	printList(list);

	cout << "last: " << list->last() << endl;
	
	return 0;
}
