#include <iostream>
#include "ListA.h"
#include "Common.h"
#
using namespace std;

ListA* newAList() {
	ListA* list = new ListA;
	list->tabSize = 5;
	list->tab = new int[list->tabSize];
	list->counter = 0;
	return list;
}

void destroyAList(ListA* list) {
	if (list != nullptr) {
		delete[] list->tab;
		delete list;
	}
}

void resize(ListA* list) {
	int size = (list->tabSize + 5);
	int *tabnew = new int[size];
	for (int i = 0; i<(list->counter); i++)
		tabnew[i] = getFromAList(list, i);
	list->tabSize = size;
	delete[] list->tab;
	list->tab = tabnew;
}

void addToAList(ListA* list, int value) {
	if (list->counter == list->tabSize)
		resize(list);
	list->tab[list->counter] = value;
	list->counter+=1;
}

int getFromAList(ListA* list, int index) {
	if (index < (list->counter))
		return list->tab[index];
	else return NaN;
}

int removeFromAList(ListA* list, int index) {
	if (index >= list->counter)
		return NaN;
	int i = index;
	int wynik = list->tab[i];
	int j = index + 1;
	for (j = (index + 1); j < (list->counter); j++) {
		list->tab[i] = list->tab[j];
		i++;
	}
	list->counter -= 1;
	return wynik;
}

int sizeA(ListA* list) {
	return list->counter;
}

auto_ptr<IteratorA> getAIterator(ListA* list) {
	IteratorA* nowy = new IteratorA;
	nowy->list = list;
	nowy->counter =0;
	return (auto_ptr<IteratorA>)nowy;
}

int iterateA(IteratorA* iterator) {
	int i= getFromAList(iterator->list,iterator->counter);
	iterator->counter ++;
	return i;
}
