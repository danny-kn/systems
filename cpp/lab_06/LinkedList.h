// Header file for linked list class
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class Type>
class LinkedList{
public:
	// Constructors and Destructors
	/* Generally every class should have at least two constructors, a
	 * default constructor and a copy constructor that creates a copy
	 * of the given object */
	LinkedList(); // default constructor
	LinkedList(const LinkedList& lst); // copy constructor
	/* Every class should have a destructor, which is responsible for
	 * cleaning up any dynamic memory allocation performed by the class.
	 * Note the special syntax for the destructor */
	~LinkedList(); // destructor

	// A new node containing the given data is inserted at the front of the list
	// data is the data to be stored
	void add(Type data);

	// A new node containing the given data is inserted at the given position in the list
	// pos specifies the (index) position to insert the new node
	// data is the data to be stored
	void insertAt(int pos, Type data);

	// The first incidence of the given data found from the list.
	// Returns true if data is found, false otherwise
	// data specifies the data to be found from the list
	bool findVal(Type data);

	// Empties the list, freeing up dynamically allocated memory
	void removeAll();

	// Prints the contents of the list to the screen, in order
	void printList();

private:
	/* A struct contains data variable (which are accessed using dot
	 * notation in the same way that object methods or attributes are
	 * accessed). Structs cannot have methods.*/
	// List node
	struct Node {
		Type data; 	// list data
		Node *next; // pointer to next item in the list
	};

	Node *head; // Pointer to the first node in the list
	int size; 	// Records the number of nodes in the list
};

template <class Type>
LinkedList<Type>::LinkedList() {
	head = NULL;
	size = 0;
}

template <class Type>
LinkedList<Type>::LinkedList(const LinkedList& lst) {
	if (lst.head == NULL) {
		head = NULL;
		size = 0;
	} else {
		// Copy first node and assign head
		/* OK, what's with the '->'?  The -> operator accesses the attribute
		 * or method of the object (or struct) that is referred to by a
		 * pointer. So "head -> data" is the contents of the data variable
		 * of the object that head points to. Note that this is synonymous
		 * with "(*head).data" but the latter syntax is ugly and confusing and
		 * is therefore rarely used. */
		head = new Node;
		head->data = lst.head->data;
		/* Now copy the rest of the list. To do this we'll need to create two
		 * temporary pointers, one to go through the old list, one node at a
		 * time, and one to keep pace in the new list, creating new nodes. */
		Node *pNewNode = head;
		Node *pOldNode = lst.head->next;
		// Repeat until the entire list is copied
		while (pOldNode != NULL) {
			pNewNode->next = new Node;
			pNewNode = pNewNode->next;
			pNewNode->data = pOldNode->data;;
			pOldNode = pOldNode->next;
		}
		pNewNode->next = NULL;
		size = lst.size;
	}
}

/* The destructor is responsible for deleting any memory that was dynamically
 * allocated by an object. If there is no such memory no destructor needs to
 * be created (the compiler automatically creates one). Because this class
 * uses pointers to create new Nodes it is necessary to write a destructor.
 * Destructors are identified by the '~' preceding the class name. There can
 * be only one destructor for a class, and it cannot have parameters. */
template <class Type>
LinkedList<Type>::~LinkedList(){
	removeAll();
}

/**************************************************************************/
// LinkedList Operations

// Adds a node to the start of the list, making it the new head
template <class Type>
void LinkedList<Type>::add(Type data) { // it is easier when you draw these out by hand...
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	size++;
}

// Inserts a new node at the given position (or index) in the list
template <class Type>
void LinkedList<Type>::insertAt(int pos, Type data) { // it is easier when you draw these out by hand...
	if(pos == 0) { add(data); return; }
	if(pos < 0) { cout << "the index cannot be negative." << endl; return; }
	if(pos > size) { cout << "the index cannot be greater than the size of the linked list." << endl; return; }

	Node *newNode = new Node;
	newNode->data = data;
	Node *p = head;

	int i = 0;
	while(i < pos - 1) {
		p = p->next;
		i++;
	}

	newNode->next = p->next;
	p->next = newNode;
	size++;
}

// find the first node containing the given data, returns true
// false otherwise
template <class Type>
bool LinkedList<Type>::findVal(Type data) { // it is easier when you draw these out by hand...
	Node *p = head;
	while (p != NULL) {
		if (p->data == data) {
			return true;
		}
		p = p->next;
	}
	return false;
}

// Empties the list by deleting each node, starting at the head
template <class Type>
void LinkedList<Type>::removeAll() {
	Node *p = head;
	// Traverse the list deleting nodes
	while (p!= NULL) {
		head = head->next; // Mustn't "lose" the next node
		delete p; // De-allocate memory
		p = head; // Go to next node
	}
	head = NULL;
	size = 0;
}

// Prints the entire list (head first) to the screen.
template <class Type>
void LinkedList<Type>::printList() {
	Node *p = head;
	cout << "[";
	// Traverse the list
	while (p != NULL) {
		cout << p -> data; 	// Print data
		p = p -> next; 		// Go to next node
		if (p != NULL) {
			cout << ","; 	// Print a comma unless at the end of the list
		}
	}
	cout << "]";
}

#endif
