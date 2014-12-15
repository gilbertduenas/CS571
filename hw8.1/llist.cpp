#ifndef LLIST_CPP
#define LLIST_CPP

#include<fstream>
#include <iostream>
#include "llist.h" 
//using namespace std;

// PURPOSE: Initialize Front and Rear to be NULL and Count = 0.
// The new list is empty. A Node is not created.
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

// PURPOSE: If the linked list is not empty, 
// we call deleteFront repeatedly to delete all nodes.
// The user is notified as each element is deleted.
// The deleted element is passed through tempElem.
llist:: ~llist()  // Destructor
{
  el_t tempElem = 0;
  while(!isEmpty())  // Test if not isEmpty.
    {
      //cout << "\nCalling the llist destructor";
      deleteFront(tempElem);
    }
  cout << endl;
} 

// PURPOSE: Test if Front and Rear are NULL. 
// ALGORITHM: Return true if Front and Rear are both pointing to NULL,
// Otherwise, return false.
bool llist::isEmpty()
{
  if((Front==NULL) && (Rear==NULL))
    return true;
  else
    return false;
}

// PURPOSE: Displays all elements from Front to Rear.
// ALGORITHM: First test if the list is empty and inform the user if so.
// Otherwise, create a temporary point and display each node. 
void llist::displayAll()
{
  if(isEmpty())
    cout << "[ empty ]" << endl;
  else
    {
      Node *tempPoint = Front;
      cout << "Displaying list....\n Event1\t Event2\t Probability\n"; 
			
      while(tempPoint!=NULL)  // Cycle through the list until the end.
	{
	  cout << "\n" << tempPoint->event1 << "\t " << tempPoint->event2 << "\t " << tempPoint->prob;  
	  tempPoint = tempPoint->Next;  // Move the pointer to the next Node.
	}
      cout << endl;
    }
}

// PURPOSE: Create a Node for the Rear of the list.
// ALGORITHM: Test if the list is empty. If so, call addFront().
// Otherwise, add a Node using the Rear Node.
void llist::addRear(char newEvent1, string newEvent2, float newProb)
{
  if(isEmpty())  // Test if the list is empty.
    {
      addFront(newEvent1, newEvent2, newProb);  // Reuse of code.
      return;
    }
  Rear->Next = new Node;  // A new Node is created at Rear.
  Rear = Rear->Next;  // The Rear pointer is moved to the new Node.
  Rear->Next = NULL;  // The new Rear->Next points to the end.
	
  //Rear->Elem = NewNum;  // The new variables are assigned a value.
	Rear->event1 = newEvent1;
	Rear->event2 = newEvent2;
	Rear->prob = newProb;
  Count++;  // The count is incremented to track the element added.
}

// PURPOSE: Remove a node from the Front of the list
// and pass the deleted value through OldNum. 
// ALGORITHM: Contains an exception handler. 
// An Underflow message will be thrown if the list is empty.
// Otherwise, the Front node will be deleted. 
void llist::deleteFront(el_t& OldNum)
{
  try  // Test for exceptions.
    {
      if(isEmpty())  // Test if the list is empty.
	{
	  throw Underflow();  // Send the error to be caught. 
	}
      else
	{
//	  OldNum = Front->Elem;  // OldNum stores the deleted value for display.
	  Node *Second;  // Temporary pointer to store Front.
	  Second = Front->Next;  // Assign the pointer to the next Node to Second.
	  delete Front;
	  Count--;  // The count is decremented to track the element deleted.
	  Front = Second;  // Assign the temporary point to the Front pointer
	  if(Front==NULL)	// Test if NULL was assigned to the Front pointer.
	    {
	      Rear=NULL;  // This means the list is empty and Rear should be NULL.
	    }	
	}
    }
  catch(llist::Underflow)  // If there is an Underflow, inform the user. 
    { 
      cout << "Underflow: The list is empty." << endl;
    }
}

// PURPOSE: Create a Node at the Front of the list.
// ALGORITHM: Test if the list is empty. 
// If so, then Rear is assigned to point to Front
// after the Node is created.
void llist::addFront(char newEvent1, string newEvent2, float newProb)
{
  bool wasEmpty = false;  // This tracks if the Node was empty.
  if(isEmpty())  // Test if the Node is empty.
    wasEmpty = true;  // If so, assign true to wasEmpty.
  Node *firstNode;  // This is a temporary Node for Front.
  firstNode = new Node;  // A new Node is created at firstNode.
  firstNode->Next = Front;  // The new Node points to the Front.
  Front = firstNode;  // The Front pointer is moved to the new Node.
	
  Front->event1 = newEvent1;  
	Front->event2 = newEvent2;  
	Front->prob = newProb;  
	
  Count++;  // Increment the counter.
  if(wasEmpty)  // Recall if the list was empty before the Node was added.
    Rear = Front;  // If so, assign the Rear pointer to the same as Front.
}

//This processes a transaction file.
bool llist::ReadTransactionFile(string filename){
  //Declare variables for the transaction file.
	char event1;
	string event2;
	float prob;
  
  //Open the transaction file and process commands one by one. 
  //Return success when complete.
  cout << "\nProcessing transaction file....\n\n";
  ifstream fin;
  fin.open(filename.data());
  if(!fin)
    {
      //Display an error message if the file does not exist.
      cout << "The file was not found." << endl;
      return false;
    }
  else
    {
      while(!fin.eof())
	{
	  fin >> event1 >> event2 >> prob;
		addRear(event1, event2, prob);
	}
      fin.close();
    }
  return true;
}
#endif //LLIST_CPP
