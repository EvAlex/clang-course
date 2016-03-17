#ifndef LIST_H
#define LIST_H

#include "Node.h"

struct List
{
	Node* top;
	Node* bottom;
};

struct Iterator
{
	Node* current;
};

List initList();

void push(List& list, double inf);

bool pop(double& inf, List& list);

void clear(List& list);

bool get(double& inf, const List& list);

bool empty(const List& list);

Iterator begin(const List& list);

Iterator end(const List& list);

bool next(Iterator& i);

bool add(List& list, Iterator& i, double inf);

bool del(List& list, const Iterator& i, double& inf);

double get(const Iterator& i);

double getNext(const Iterator& i);

bool check(const Iterator& i);

bool operator ==(const Iterator& i1, const Iterator& i2);

bool operator !=(const Iterator& i1, const Iterator& i2);

bool set(const Iterator& i, double inf);

bool setNext(const Iterator& i, double inf);

#endif