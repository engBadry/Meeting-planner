#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
/*
 * BST.h
 *
 *  Created on: Jun 5, 2021
 *      Author: student
 */
#include <string>
#include <iostream>
using namespace std;
class BinaryTree {
public:
	BinaryTree * left();
	BinaryTree * right();
	BinaryTree();
	bool isEmpty();
	void insert(const int &hour, const int &day, const string &title);
	void getData(int &hour1, int &day1, string &title1);
	void makeleft(BinaryTree * T1);
	void makeright(BinaryTree * T1);
	void Modify(const int &hour, const int &day, const string &title);
	BinaryTree * retrieve( int &hour, int &day);
private:
	bool nullTree;
	int day;
	int hour;
	string title;
	BinaryTree * leftTree;
	BinaryTree * rightTree;
};



#endif // BST_H_INCLUDED
