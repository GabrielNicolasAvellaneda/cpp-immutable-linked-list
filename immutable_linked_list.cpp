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

	private:
	       static int size(List *list, int n) {
			if (list->isEmpty()) {
				return n;
			}
			return size(list->tail(), n + 1);
		}

	       static List* reverse(List* list, List* reversed) {
		       if (list->isEmpty()) {
				return reversed;
		       }

		       reverse(list->tail(), reversed->insert(list->head()));  
	       }

	public:
		static List* reverse(List *list) {
			List::reverse(list, new List());
		}

		static int length(List *list) {
			return size(list);
		}

		static int size(List* list) {
			return List::size(list, 0);
		}

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

		int size() {
			List::size(this);
		}

		int length() {
			List::length(this);
		}

		List* reverse() {
			List::reverse(this);
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
	cout << "size: " << list->size() << endl;

	List* reversed = list->reverse();
	cout << "last at reversed list: " << reversed->last() << endl;
	
	return 0;
}
