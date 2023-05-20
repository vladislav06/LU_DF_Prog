/******************************************************************************************************
basic prog
*******************************************************************************************************/

/// Autors: Vladislavs Agarkovs
/// Veidots: 13.09.2022


#include <iostream>

using namespace std;

template <typename T>
struct node {
  T value;
  node * next;
};


int main() {

  int ok;

  //create and fill linked list
  node<int> head;

  node<int> * element = &head;

  for(int i = 0; i < 10; i++){
    element->value = i;
    element->next = new node<int>;
    element = element->next;
  }



  do
  {
    int n;

    cout<<"enter number: ";
    cin>>n;
    //try to find;
    bool found = false;
    node<int> * element = &head;
    for(int i = 0; i < 10; i++){
        if(element->value == n){
          found = true;
          break;
        }
         element = element->next;
    }

    cout<<"element was "<<(found?"":"not ")<<"found\n";

    std::cout << "Vai turpināt (1) vai beigt (0)?" << std::endl;
    std::cin >> ok;
  } while (ok == 1);

  return 0;
}
/***********************  Testu plāns ***********************
       output asd
*************************************************************/

