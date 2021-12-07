#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//Generic Linkedlist
template <class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* prev;

	Node(int data) :next(NULL), prev(NULL) {
		this->data = data;
	}
	T getData()
	{
		return data;
	}
};



template <class T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;

public:
	List() :head(NULL), tail(NULL) {}
	~List() {
		Node<T>* curr = head;
		Node<T>* next;
		while (curr) {
			next = curr->next;
			delete(curr);
			curr = next;
		}
	}

	void addDataToEnd(int data) { addNodeToEnd(new Node<T>(data)); }


	void addNodeToEnd(Node<T>* node) {
		if (this->head == NULL) {//if the list is empty
			this->head = node;
			this->tail = node;
		}
		else {
			this->tail->next = node;
			node->prev = tail;
			this->tail = node;
		}
	}


	bool isExist(T data) {//check if there is node with same data
		bool res = false;
		Node<T>* curr = head;
		while (curr) {
			if (curr->data == data) {
				res = true;
				break;
			}
			curr = curr->next;
		}
		return res;
	}



	Node<T>* getHead() { return head; }
	Node<T>* getTail() { return tail; }

	void clear() {
		Node<T>* curr = head;
		Node<T>* next;
		while (curr) {
			next = curr->next;
			delete(curr);
			curr = next;
		}
		head = NULL;
		tail = NULL;
	}
	bool isEmpty() { return head == NULL ? true : false; }

	bool IsAdjancent(int v) {
		bool res = false;
		Node<T>* curr = head;
		while (curr) {
			if (curr->data == v) {
				res = true;
				break;
			}
		}
		return res;
	}
};
#endif // !LINKEDLIST

