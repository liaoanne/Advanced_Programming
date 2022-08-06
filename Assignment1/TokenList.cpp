// TokenList.cpp
// TokenList class member-function definitions.
// Created by Anne Liao (40215517) on May 19, 2022.

#include "TokenList.h" // include definition of class TokenList from TokenList.h

/** Constructors */

// Default constructor, creates an empty list
TokenList::TokenList()
	: head{nullptr}, tail{nullptr}, theSize{ 0 } { // member init
	// empty body
}

// Copy constructor
TokenList::TokenList(const TokenList& list)
	: TokenList{} {
	// copy list data to this
	copy(list);
}

// Move constructor
TokenList::TokenList(TokenList&& list) noexcept
	: head{ list.head }, tail{ list.tail }, theSize{ list.theSize } { // reassign list data to this
	// set list data to default data
	list.head = nullptr;
	list.tail = nullptr;
	list.theSize = 0;
}

/** Assignment operator overloading */

// Copy assignment operator
TokenList& TokenList::operator=(const TokenList& rhs) {
	if (&rhs != this) {
		// delete original list data
		clear();

		// copy rhs data to this
		copy(rhs);
	}
	return *this;
}

// Move assignment operator
TokenList& TokenList::operator=(TokenList&& rhs) noexcept {
	if (&rhs != this) {
		// delete original list data
		clear();

		// reassign rhs data to this
		head = rhs.head;
		tail = rhs.tail;
		theSize = rhs.theSize;

		// set rhs data to default data
		rhs.head = nullptr;
		rhs.tail = nullptr;
		rhs.theSize = 0;
	}
	return *this;
}

/** Destructor */

// Destructor (and a virtual one in this example)
TokenList::~TokenList() {
	// delete list data
	clear();
}

/** Public class member-function defintions */

// Determines whether this list is empty
bool TokenList::empty() const {
	return theSize == 0;
}

// Returns theSize
size_t TokenList::size() const {
	return theSize;
}

// Prints the entire list to sout
void TokenList::print(std::ostream& sout) const {
	for (TNode* temp{ head }; temp != nullptr; temp = temp->next) {
		sout << temp->theToken << std::endl;
	}
}

// Returns the token at the front of this list
const Token& TokenList::front() const {
	return head->theToken;
}

// Returns the token at the end of this list
const Token& TokenList::back() const {
	return tail->theToken;
}

// Adds aToken at its sorted position into the list so as to maintain the ascending order of the tokens in the list
void TokenList::addSorted(const Token& aToken) {
	ArrayList list{ aToken.getNumberList() };
	int lineNumber;
	list.get(list.size() - 1, lineNumber);
	addSorted(aToken.c_str(), lineNumber);
}

// Equivalent to addSorted(Token(str,lineNum)); but it's up to you to decide how you want to implement it.
void TokenList::addSorted(const std::string& str, int lineNum) {
	Token aToken(str.c_str(), lineNum);
	// get the storted position for the token
	TNode* nodePtr{ lookup(aToken) };

	// no nodes in the list, add to front
	if (nodePtr == nullptr) {
		addFront(aToken);
		return;
	}

	// token already a node, add line number
	if ((nodePtr->theToken).compare(aToken) == 0) {
		(nodePtr->theToken).addLineNumber(lineNum);
		return;
	}
	else {
		// token not a node, add new node at sorted position
		addAfter(nodePtr, aToken);
		return;
	}
}

// If the list is nonempty, removes the node at the front of the list and returns true; otherwise, returns false
bool TokenList::removeFront() {
	if (!empty()) {
		TNode* oldhead{ head };
		head = head->next;
		delete oldhead;
		--theSize;

		// no more nodes remaining, set tail to null
		if (head == nullptr) {
			tail = nullptr;
		}
		return true;
	}
	return false;
}

// If the list is nonempty, removes the node at the end of the list and returns true; otherwise, returns false
bool TokenList::removeBack() {
	if (!empty()) {
		// if there is only one node in the list
		if (theSize == 1) {
			delete head;
			head = nullptr;
			tail = nullptr;
			--theSize;
			return true;
		}

		// if multiple nodes in the list, find the second last node
		TNode* secondLast{ head };
		while (secondLast->next != tail) {
			secondLast = secondLast->next;
		}

		// delete the last node and set the new tail
		delete tail;
		tail = secondLast;
		secondLast->next = nullptr;
		--theSize;
		return true;
	}
	return false;
}

// Determines whether aToken is in the list
bool TokenList::search(const Token& aToken) const {
	if (!empty()) {
		TNode* current{ head };
		// iterate through the list
		while (current != nullptr) {
			// chech for match in list
			if ((current->theToken).compare(aToken) == 0) {
				return true;
			}
			current = current->next;
		}
		// reached end of list, no match
		return false;
	}
	return false;
}

// Adds a new node storing aToken to the front of the list
void TokenList::addFront(const Token& aToken) {
	TNode* newNode{ new TNode(aToken) };
	newNode->next = head;
	head = newNode;
	++theSize;
	if (tail == nullptr) {
		tail = head;
	}
	return;
}

// Adds a new node storing aToken to the end of the list
void TokenList::addBack(const Token& aToken) {
	TNode* newNode{ new TNode(aToken) };
	if (tail == nullptr) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	++theSize;
}

// Releases all the nodes in this TokenList
void TokenList::clear() {
	while (!empty()) {
		removeFront();
	}
}

/** Private class member-function defintions */

// Removes the node to which nodePtr points and returns true; otherwise, returns false
bool TokenList::remove(TNode* nodePtr) {
	if (nodePtr != nullptr) {
		// nodePtr is pointing to remove the head
		if (nodePtr == head) {
			removeFront();
			--theSize;
			return true;
		}
		
		// nodePtr is pointing to remove the tail
		if (nodePtr == tail) {
			removeBack();
			--theSize;
			return true;
		}

		// nodePtr is pointing to remove element in the middle of the lis
		for (TNode* current{ head }; current != nullptr; current = current->next) {
			// find the node right before the node we want to delete
			if ((current->next->theToken).compare(nodePtr->theToken) == 0) {
				TNode* delNode{ current->next }; // get the node to be deleted
				current->next = delNode->next; // rearrange the next node sequence
				delete delNode;
				--theSize;
				return true;
			}
		}
	}
	return false;
}

// If aToken is in the list, it returns a pointer to the node whose token is equal to aToken; otherwise, it returns a pointer to the node after which aToken would be inserted in the sorted list
TokenList::TNode* TokenList::lookup(const Token& aToken) const {
	// no nodes in list, token should be the head
	if (head == nullptr) {
		return nullptr;
	}

	// token should be at the front of the list
	if (aToken.compare(head->theToken) < 0) {
		return nullptr;
	}

	TNode* prev{ head };
	TNode* current{ head->next };
	
	while (current != nullptr) {
		if ((current->theToken).compare(aToken) > 0) {
			return prev;
		}
		prev = current;
		current = current->next;
	}
	return tail;
}

// Adds a new node storing aToken after the node to which p points. If p is nullptr, it adds the node to the front of the list.
void TokenList::addAfter(TNode* p, const Token& aToken) {
	if (p != nullptr) {
		TNode* newNode{ new TNode(aToken) };
		if (p->next != nullptr) {
			TNode* tempNext{ p->next };
			p->next = newNode;
			newNode->next = tempNext;
			++theSize;
		}
		else {
			// pointer is at the back of the list, add to back
			addBack(aToken);
		}
	}
	else {
		// pointer is at the front of the list, add to front
		addFront(aToken);
	}
}

// Copies list into this list
void TokenList::copy(const TokenList& list) {
	// make sure this is empty
	theSize = 0;
	head = nullptr;

	// check if list is empty, and exit if empty
	if (list.empty()) {
		return;
	}

	// copy the list data to this list
	TNode* current{ list.head };
	head = new TNode(current->theToken, nullptr); // copy head node from list
	theSize = 1;

	// copy the remaining nodes
	TNode* lastNode{ head };
	current = current->next;
	while (current) {
		TNode* newNode{ new TNode(current->theToken, nullptr) };
		lastNode->next = newNode;

		lastNode = newNode;
		current = current->next;

		++theSize;
	}
}