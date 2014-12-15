#ifndef LLIST_H
#define LLIST_H
#include<string>

using namespace std;

typedef int el_t ;  // el_t is an alias for integer

// List node is defined here as a struct Node in order to save space. 
struct Node
{
  Node *Next;  // next is the pointer to the next node
	
	char event1;
	string event2;
	float prob;
};

class llist
{
 protected:
  Node *Front;  // Front  pointer 
  Node *Rear;  // Rear pointer
  int  Count;  // Counter for the number of elements
  
 public:  
  class Underflow{};  // exception handling class  
  class OutOfRange{};  // exception handling class  
  
  llist();  // constructor  
  ~llist();  // destructor
  
  // PURPOSE: check if the stack is empty 
  // HOW TO CALL: not applicable  
  bool isEmpty();
  
  // PURPOSE: display elements in linked list
  // HOW TO CALL: not applicable  
  void displayAll();
  
  // PURPOSE: add a Node to the end of the linked list
  // HOW TO CALL: pass the integer to be stored at the rear
  void addRear(char event1, string event2, float prob);
  
  // PURPOSE: delete the beginning Node of the linked list
  // HOW TO CALL: pass the integer to be deleted at the front
  void deleteFront(el_t& OldNum);
  
  // PURPOSE: add a Node to the start of the linked list
  // HOW TO CALL: pass the integer to be stored at the front
  void addFront(char event1, string event2, float prob);
  
	bool ReadTransactionFile(string filename);
};
#endif // LLIST_H
