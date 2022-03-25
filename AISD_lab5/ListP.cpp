#include <iostream>
#include "Common.h"
#include "ListP.h"

using namespace std;

Element* newElement(int value);

ListP* newPList() {
	ListP* list = new ListP;
	list->first = NULL;
	list->last = NULL;
	list->rozmiar = 0;
	return list;
}

void destroyPList(ListP* list) {
	if (list != NULL) {
		while (list->first != NULL) {
			Element* curr = list->first;
			if (list->first == list->last) list->first = NULL;
			else list->first = list->first->next;
			delete curr;
		}
		delete list;
	}
}

void addToPList(ListP* list, int value) {
	Element* adres= newElement(value);
	list->rozmiar+=1;
	if (list->first == NULL) {
		list->first = adres;
	}
	else if (list->first->next == NULL)
		list->first->next = adres;
	else
		list->last->next = adres;
	list->last = adres;

}

Element* search(ListP* list, int value) {;
	Element* curr = list->first;
	int w = curr->value;
	while(w!= value || curr!= NULL){
		w = curr->value;
		curr = curr->next;
	}
	return curr;
}

int getFromPList(ListP* list, int index) {
	Element* curr = list->first;
	int i = 0;
	while (curr!=NULL&&i<=index) {
 
		if (i == index) {
			return curr->value;
			break;
		}
		curr = curr->next;
		i++;	
}
	return NaN;
}

Element* newElement(int value) {
	Element* element = new Element;
	element->value = value;
	element->next = NULL;
	return element;
}

int removeFromPList(ListP* list, int index) {
	Element* curr = list->first;
	int i = 0;
	Element* prev = NULL;
	while (curr != NULL && i < index) {
		prev = curr;
		curr = curr->next;
		i++;
	}
	int value;
	if (curr == NULL) { //Będzie null jeśli lista jest pusta
		list->last = prev;
		value = NaN;
	}
	else { 
		if (prev != NULL) { //Sprawdzant czy to nie pierwszy element listy		
			prev->next = curr->next;			
		}
		else {
			list->first = curr->next;
		}		
		if (curr->next == NULL) { //Jak koniec kolejki
			list->last = prev;
		}
		value = curr->value;
		list->rozmiar--;
		delete curr;
	}
	return value;
}

int sizeP(ListP* list) {
	if (list!=NULL)
		return list->rozmiar;
	return NaN;
}

auto_ptr<IteratorP> getPIterator(ListP* list) {
	IteratorP* wynik = new IteratorP;
	wynik->list = list;
	wynik->curr = list->first;
	wynik->counter = 0;
	return (auto_ptr<IteratorP>) wynik;
}

int iterateP(IteratorP* iterator) {
	Element* e = iterator->curr;
	if (e == NULL)
		return NaN;
	iterator->curr = e->next;
	iterator->counter=+1;

	return e->value;
}
