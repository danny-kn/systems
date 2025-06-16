// Implementation of the LinkedList class

#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std; // needed for cout, cin to be recognised

// Default constructor
LinkedList::LinkedList() {
	head = NULL;
	size = 0;
}

// Copy constructor
LinkedList::LinkedList(const LinkedList& lst) {
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
LinkedList::~LinkedList(){
	removeAll();
}

/**************************************************************************/
// LinkedList Operations

// Adds a node to the start of the list, making it the new head
void LinkedList::add(int x) {
	// Your code here
}

// Inserts a new node at the given position (or index) in the list
void LinkedList::insertAt(int pos, int x) {
	// Your code here
}

// find the first node containing the given data, returns true
// false otherwise
bool LinkedList::findVal(int x) {
	// Your code here
}

// Empties the list by deleting each node, starting at the head
void LinkedList::removeAll() {
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
void LinkedList::printList() {
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
