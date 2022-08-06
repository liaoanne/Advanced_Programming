// TokenList.h
// TokenList class definition.
// Member functions are defined in TokenList.cpp
// Created by Anne Liao (40215517) on May 19, 2022.

#ifndef TOKENLIST_H_ // prevent multiple inclusions of header
#define TOKENLIST_H_
#include <iostream>

#include "Token.h"

// A class representing a singly linked list of TNodes
class TokenList {
private:
	// a private "member type"
	struct TNode
	{
		Token theToken; // the token contained in this node
		TNode* next; // Pointer to the next node or nullptr

		// Constructor
		TNode(const Token& aToken, TNode* next = nullptr) :
			theToken(aToken), next(next) {}
		TNode() = delete; // default ctor

		TNode(const TNode & other) = delete; // copy ctor
		TNode(TNode && other) = delete; // move ctor
		TNode & operator=(const TNode & other) = delete; // copy assignment
		TNode & operator=(TNode && other) = delete; // move assignment
		virtual ~TNode() = default;
	}; // end of class TNode

// beginning class TokenList
public:
// ... public members of TokenList
	TokenList(); // Default constructor, creates an empty list

	TokenList(const TokenList& list); // Copy constructor
	TokenList(TokenList&& list) noexcept; // Move constructor
	TokenList& operator=(const TokenList& rhs); // Copy assignment operator
	TokenList& operator=(TokenList&& rhs) noexcept; // Move assignment operator
	virtual ~TokenList(); // Destructor (and a virtual one in this example)

	bool empty() const; // Determines whether this list is empty
	size_t size() const; // Returns theSize
	void print(std::ostream& sout) const; // Prints the entire list to sout
	const Token& front() const; // Returns the token at the front of this list
	const Token& back() const; // Returns the token at the end of this list
	void addSorted(const Token& aToken); // Adds aToken at its sorted position into the list so as to maintain the ascending order of the tokens in the list
	void addSorted(const std::string& str, int lineNum); // Equivalent to addSorted(Token(str,lineNum)); but it's up to you to decide how you want to implement it.
	bool removeFront(); // If the list is nonempty, removes the node at the front of the list and returns true; otherwise, returns false
	bool removeBack(); // If the list is nonempty, removes the node at the end of the list and returns true; otherwise, returns false
	bool search(const Token& aToken) const; // Determines whether aToken is in the list
	void addFront(const Token& aToken); // Adds a new node storing aToken to the front of the list
	void addBack(const Token& aToken); // Adds a new node storing aToken to the end of the list
	void clear(); // Releases all the nodes in this TokenList

private:
// ... private members of TokenList
	TNode* head{ nullptr }; // Pointer to the first node
	TNode* tail{ nullptr }; // Pointer to the last node
	size_t theSize{ 0 }; // Number of nodes in this list

	bool remove(TNode* nodePtr); // Removes the node to which nodePtr points and returns true; otherwise, returns false
	TNode* lookup(const Token& aToken) const; // If aToken is in the list, it returns a pointer to the node whose token is equal to aToken; otherwise, it returns a pointer to the node after which aToken would be inserted in the sorted list
	void addAfter(TNode* p, const Token& aToken); // Adds a new node storing aToken after the node to which p points. If p is nullptr, it adds the node to the front of the list.
	void copy(const TokenList& list); // Copies list into this list
};

// Overload print stream
inline std::ostream& operator<<(std::ostream& sout, const TokenList& list) {
	list.print(sout);
	return sout;
}
#endif