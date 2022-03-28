#include "BST.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
BinaryTree::BinaryTree() {
	nullTree = true;
	leftTree = NULL;
	rightTree = NULL;
}
bool BinaryTree::isEmpty() {
	return nullTree;
}
void BinaryTree::getData(int &hour1, int &day1, string &title1) {
	assert(!isEmpty());
	hour1 = hour;
	day1 = day;
	title1 = title;
}
void BinaryTree::insert(const int &hour2, const int &day2,
		const string &title2) {
	if (nullTree) {
		nullTree = false;
		leftTree = new BinaryTree;
		rightTree = new BinaryTree;
		day = day2;
		hour = hour2;
		title = title2;
	} else if (day == day2) {
		if (hour2 < hour) {
			leftTree->insert(hour2, day2, title2);
		} else if (hour2 > hour) {
			rightTree->insert(hour2, day2, title2);
		} else if (hour == hour2) {
			cout << "Conflict " << day2 << " " << hour2 << endl;
		}
	}
}
BinaryTree* BinaryTree::retrieve(int &hour3, int &day3) {
	if (nullTree || day3 == day) {
		if (nullTree || hour3 == hour)
			return this;
		else if (nullTree || hour3 < hour) {
			return leftTree->retrieve(hour3, day3);
		} else if (nullTree || hour3 > hour) {
			return rightTree->retrieve(hour3, day3);
		}
	} else if (nullTree || day3 < day) {
        return leftTree->retrieve(hour3, day3);
		/*if (nullTree || hour3 == hour)
			return this;
		else if (nullTree || hour3 < hour) {
			return leftTree->retrieve(hour3, day3);
		} else if (nullTree || hour3 > hour) {
			return rightTree->retrieve(hour3, day3);
		}*/
	} else if (nullTree || day3 > day) {
        return rightTree->retrieve(hour3, day3);
		/*if (nullTree || hour3 == hour)
			return this;
		else if (nullTree || hour3 < hour) {
			return leftTree->retrieve(hour3, day3);
		} else if (nullTree || hour3 > hour) {
			return rightTree->retrieve(hour3, day3);
		}*/
	}
}
BinaryTree * BinaryTree::left(){
	assert(!isEmpty());
	return leftTree;
}
BinaryTree * BinaryTree::right(){
	assert(!isEmpty());
	return rightTree;
}
void BinaryTree::makeright(BinaryTree * T1){
	assert(!isEmpty());
	assert(right()->isEmpty());
	delete right();
	rightTree=T1;
}
void BinaryTree::makeleft(BinaryTree * T1){
	assert(!isEmpty());
	assert(left()->isEmpty());
	delete left();
	leftTree=T1;
}
void BinaryTree::Modify(const int &hour4, const int &day4, const string &title4)
{
	BinaryTree * ptr1;
	ptr1=retrieve(hour4,day4);
	ptr1->title=title4;
}
