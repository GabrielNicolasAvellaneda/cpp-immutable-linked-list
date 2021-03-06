#include <iostream>
#include <cstddef>
#include <vector>

#define NO_SUCH_ELEMENT_EXCEPTION 10
#define UNSUPPORTED_OPERATION_EXCEPTION 12
#define INDEX_OUT_OF_BOUNDS_EXCEPTION 13

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

	       static List* take(int n, List* list, List* result) {
			if (list->isEmpty() || n == 0) {
				return result->reverse();
			}
			return take(n - 1, list->tail(), result->insert(list->head()));  
	       }

	       static int indexOf(int n, List* list, int index) {
		       if (list->isEmpty())
			       return -1;

		 	if (list->head() == n) {
				return index;
			}

		       return indexOf(n, list->tail(), index + 1);
	       }

	       Node* headNode() {
			return _head;
	       }

	       static Node* _lastNode(List* list) {
			if (list->isEmpty())
				throw NO_SUCH_ELEMENT_EXCEPTION;

			auto tail = list->tail();
			if (tail->isEmpty())
				return list->headNode();

			return _lastNode(tail);
	       }

		Node* _lastNode() {
			return List::_lastNode(this);	
		}

	public:

	       static List* init(List* list) {
		       if (list->isEmpty())
			       throw UNSUPPORTED_OPERATION_EXCEPTION;

			return take(list->size()-1, list);
	       }

	       static int indexOf(int n, List* list) {
			return indexOf(n, list, 0);	
	       }

	       static int apply(int n, List* list) {
			if (n < 0 || n >= length(list))
				throw INDEX_OUT_OF_BOUNDS_EXCEPTION; 

			List* result = take(n + 1, list);
			return result->head();
	       }
		
		static List* take(int n, List* list) {
			return take(n, list, new List());
		}

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
			Node* lastNode = _lastNode(list);
			return lastNode->value;
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
			return this;
		}

		List* append(int value) {
			Node *node = new Node;
			node->value = value;
			if (isEmpty()) {
				_head = node;	
			} else {
				Node* lastNode = _lastNode();
				lastNode->_next = node; 
			}
			return this; 
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

		List* take(int n) {
			List::take(n, this);
		}

		int apply(int n) {
			List::apply(n, this);
		}

		int indexOf(int n) {
			List::indexOf(n, this);
		}

		List* init() {
			return List::init(this);
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

	int result = list->apply(0); 
	cout << "value at index 0: " << result << endl;  
	
	List* taken = list->take(2);
	cout << "taken list size: " << taken->size() << endl;

	int index = list->indexOf(6);
	cout << "index: " << index << endl;

	List* init = list->init();
	cout << "init list size: " << init->size() << endl;

	List* appendedList = list->append(6);  
	printList(appendedList);

	return 0;
}
