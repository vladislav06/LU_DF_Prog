#include "List.h"
#include <stdexcept>
#include <string>

template <typename T> List<T>::List() {}

template <typename T> List<T>::~List() {
  while (head != nullptr) {
    Element *del = head;
    head = head->next;
    delete del;
  }
}

template <typename T> void List<T>::push_back(T data) {
  if (head == nullptr) {
    head = new Element(data, nullptr);
    return;
  }
  Element *elem = head;
  while (elem->next != nullptr) {
    elem = elem->next;
  }
  elem->next = new Element(data, nullptr);
}

template <typename T> void List<T>::push_front(T data) {
  Element *elem = new Element(data, head);
  head = elem;
}

template <typename T> int List<T>::find(T data) {
  Element *elem = head;
  int i = 0;
  while (elem->next != nullptr) {
    if (elem->data == data) {
      return i;
    }
    i++;
    elem = elem->next;
  }
  return -1;
}

template <typename T> T List<T>::getAt(int i) {
  if (i < 0) {
    throw std::out_of_range("Index is out of range(" + std::to_string(i) + ")");
  }
  Element *elem = head;
  for (; i > 0; i--) {
    elem = elem->next;
  }
  return elem->data;
}

template <typename T> T List<T>::operator[](int i) { return getAt(i); }
