#include "List.h"

List initList()
{
	List l = { nullptr, nullptr };
	return l;
}

void push(List& list, double inf)
{
	Node* temp = new Node;
	temp->inf = inf;
	temp->next = list.top;

	if (!list.top)
		list.bottom = temp;

	list.top = temp;
}

bool pop(double& inf, List& list)
{
	if (!list.top)
		return false;

	Node* temp = list.top;
	inf = list.top->inf;
	list.top = list.top->next;
	delete temp;

	if (!list.top)
		list.bottom = nullptr;
}

void clear(List& list)
{
	while (list.top)
	{
		Node* temp = list.top;
		list.top = list.top->next;
		delete temp;
	}
	list.bottom = nullptr;
}

bool get(double& inf, const List& list)
{
	if (!list.top)
		return false;

	inf = list.top->inf;
	return true;
}

bool empty(const List& list)
{
	return !list.top;
}

Iterator begin(const List& list)
{
	Iterator i = { list.top };
	return i;
}

Iterator end(const List& list)
{
	Iterator i = { list.bottom };
	return i;
}

bool next(Iterator& i)
{
	if (!i.current->next)
		return false;

	i.current = i.current->next;
	return true;
}

bool add(List& list, Iterator& i, double inf)
{
	if (!i.current && list.top)
		return false;

	Node* temp = new Node;
	temp->inf = inf;
	if (!list.top)
	{
		temp->next = nullptr;
		list.top = list.bottom = i.current = temp;
	}
	else if (!i.current->next)
	{
		temp->next = nullptr;
		list.bottom = i.current->next = temp;
	}
	else
	{
		temp->next = i.current->next;
		i.current->next = temp;
	}

	return true;
}

bool del(List& list, const Iterator& i, double& inf)
{
	if (!list.top || !i.current || !i.current->next)
		return false;

	Node* temp = i.current->next;
	inf = temp->inf;
	i.current->next = i.current->next->next;
	delete temp;

	if (!i.current->next)
		list.bottom = i.current;

	return true;
}

double get(const Iterator& i)
{
	return i.current ? i.current->inf : 0.;
}

double getNext(const Iterator& i)
{
	return i.current && i.current->next ? i.current->next->inf : 0;
}

bool check(const Iterator& i)
{
	return i.current;
}

bool operator ==(const Iterator& i1, const Iterator& i2)
{
	return i1.current == i2.current;
}

bool operator !=(const Iterator &i1, const Iterator& i2)
{
	return i1.current != i2.current;
}

bool set(const Iterator& i, double inf)
{
	if (!i.current)
		return false;

	i.current->inf = inf;
	return true;
}

bool setNext(const Iterator& i, double inf)
{
	if (!i.current || !i.current->next)
		return false;

	i.current->next->inf = inf;
	return true;
}