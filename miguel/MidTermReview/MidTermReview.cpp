// MidTermReview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

#define QUESTION4

#ifdef QUESTION1
//  This is O(1)
#endif

#ifdef QUESTION2
//  This is O(n)
#endif

#ifdef QUESTION3
int function1(int n) {
	int rc = 1;
	for (int i = 0; i < n; ++i) {
		rc += 1;
	}
	return rc;
}


int function2(int n) {
	int rc = 1;
	for (int i = 0; i < n; ++i) {
		for (int i = 0; i < n; ++i) {
			rc += 1;
		}
	}
	return rc;
}

int f1(int n) {
	int rc1 = function1(n);
	int rc2 = function2(n);
	return rc1 + rc2;
}
#endif
#ifdef QUESTION4
bool isPalindrome(char* str, int len) {
	bool res = false;
	if (len == 0 || len == 1) {//Consider odd number of characters
		res = true;
	}
	else {
		if (str[0] == str[len - 1] && isPalindrome(&str[1], len - 2)){
			res = true;
		}
		else {
			res = false;
		}
	}
	return res;
}
bool isPalindrome(char* str) {
	bool res = false;
	int len = strlen(str);
	res = isPalindrome(str, len);
	if (res == true) cout << str << " is a palindrome" << endl;
	else cout << str << " is not a palindrome" << endl;
	return res;
}
#endif
int main()
{
#ifdef QUESTION3
	int n[5] = {5000, 10000, 20000, 40000, 80000};
	double startTime, endTime, totalTime;
	for (int i = 0; i < 5; ++i) {
		startTime = GetTickCount();//milliseconds
		f1(n[i]);
		endTime = GetTickCount();//milliseconds
		totalTime = endTime - startTime;
		cout << "n:" << setw(5) << n[i] << " totalTime:" << setw(5) << totalTime << endl;
	}
#endif

#ifdef QUESTION4
	char testStr[] = "abbcbba";
	bool isPal = isPalindrome(testStr);
#endif

#ifdef QUESTION5
	//Negative values put in the queue
	//Positive values put on the stack
#endif

#ifdef QUESTION6
//	Linked List Implementation
/*		To implement a stack using a linked list, we have to consider the type of linked list
        we would use and which end of the list we would want to insert to.

		The simplest linked list is a singly list.If this linked list was implemented with
		just a pointer to the first node, insertion would be O(1) at front of list, O(n)
		at back of list.removal is O(1) at front of list and O(n) at back of list. If we
		added an end pointer to the list, then insertion to back of list can be O(1) also,
		however removing from the back of the list will still be O(n).

		If we were to insert always at front of list, then the most recently added item
		would be at the front of the list. Thus, removal must occur from the front as we
		always remove the most recently added item.Since we can do both quickly with a
		simple singularly linked list, that is all we will need to do.*/
#endif

#ifdef QUESTION7
	//   0     1     2     3     4     5      6     7     8     9
	// gamma                   apple cherry orange      alpha  beta
	//   8                       4     5      4           8     9
	//
	// Remove apple
	//   0     1     2     3     4     5     6     7     8     9
	// gamma                  orange cherry            alpha  beta
	//   8                       4     5                 8     9
	//
	// Remove beta
	//   0     1     2     3     4     5     6     7     8     9
	//                        orange cherry            alpha  gamma
	//                           4     5                 8     8
#endif

#ifdef QUESTION8
//	Queue Implementation
/*	One way that we can handle this is to track two indices instead of one.
    The first is the index of the element at the front of the list.
	The second is the index of the element at the back of the list.
	When you insert, insert to the index of the back element and increment the index for back.
	When you remove, remove by incrementing the index of the front.
	The second part of the implementation is that we need to treat the array as if it is a ring.
	That is, the next element of the last element is the first element and the previous element
	of the first element is the last element. If we do not, we will quickly create a list with
	lots of unused space at the front of the list and run out of space.*/
#endif

#ifdef QUESTION9
	template <typename T>
	iterator SelfAdjustingList::search(const T& v) {
		Node* curr = front_->next_;
		Node* currprev;
		while (curr != back_ && curr->value_ != v) {
			currprev = curr;
			curr = curr->next_;
		}
		if (it != end()) {
			currprev->next_ = curr->next_;
			curr->next_ = front_->next_;
			front->next_ = curr;
		}
		return iterator(curr);
	}
#endif

#ifdef QUESTION10
	// MergeSort the following:
    15 8 9 7 11 2 4 10

	15 8 9 7    11 2 4 10
	15 8    9 7    11 2    4 10
	15    8    9    7    11    2    4    10
	8 15    7 9    2 11    4 10
	7 8 9 15    2 4 10 11
	2 4 7 8 9 10 11 15
	*/
#endif
	return 0;
}
