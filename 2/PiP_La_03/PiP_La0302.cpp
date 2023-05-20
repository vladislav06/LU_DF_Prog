/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022

#include <iostream>
#include <type_traits>

using namespace std;

template <typename T> struct node {
  T value;
  node *next;
};

template <typename T>

void print(node<T> *head) {
  while (head != nullptr) {
    cout << head->value << ", ";
    head = head->next;
  }
}

int main() {

  int ok;

  // create and fill linked list
  node<int> *head = new node<int>;

  node<int> *tmp = head;

  for (int i = 0; i < 10; i++) {
      tmp->value = i;
      tmp->next = new node<int>;
      tmp = tmp->next;
  }
  //set last element


  do {
    int n;
    cout << "before:";
    print(head);
    cout << "enter number: ";
    cin >> n;
    // try to find and delete;
    //check first element
    if(head->value == n){
        node<int> *del = head;
        head = head->next;
        delete del;
    }
    node<int> *element = head;
    while (element != nullptr && element->next != nullptr) {
      if(element->next->value == n){
          node<int> *del = element->next;
          element->next = element->next->next;
          delete del;
      }
      element = element->next;
    }

    cout << "after:";
    print(head);

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

    node<int> *del = head;
  while(head!= nullptr){
      head=head->next;
      delete del;
      del = head;
  }

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/
