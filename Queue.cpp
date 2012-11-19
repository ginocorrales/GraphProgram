/* This is the implementation of the Queue Class using a Linked List
 * Author: Gino P. Corrales-Delgado
 * IT 279  -  9/28/2012
 */
#include <string>
#include <iostream>
using namespace std;

#include "Queue.h"

Queue::Queue()
{
  this -> head = NULL;
  this -> tail = NULL;
}

Queue::Queue(const Queue &orig)
{
  this -> copy(orig);
}

Queue::~Queue()
{
  this -> ClearQueue();            
}
///*
void Queue::Enqueue(int min) 
{
  Node* current = new Node(min);
  if(this -> isEmpty())
    this -> head = current;
  else
    this -> tail -> next = current;
  
  this -> tail = current;   
}
//*/
/*
void Queue::Enqueue(int data[]) 
{
  Node* current = new Node(data);    
  Node* ptr = this -> head;
  Node* ptrPrev = NULL;
  
  if(this -> isEmpty())
  {
    this -> head = current;
    this -> tail = current;
  }
  else
  {
    while(ptr != NULL && ptr -> data[0] < data[0])
    {
      ptrPrev = ptr;
      ptr = ptr -> next;
    } 
    if(ptr == NULL)
    {
      tail -> next = current;
      tail = current; 
    }
    else if(ptr == this -> head) 
    {
      current -> next = this -> head;
      this -> head = current;
    }
    else
    {
      ptrPrev -> next = current;
      current -> next = ptr;
    }
  }

  // delete [] all the nodes that I used with new...
}
*/

void Queue::Dequeue()  
{
  Node* tempNode = this -> head;
  this -> head = this -> head -> next;
  delete tempNode;
}

Queue& Queue::operator =(const Queue &rhs)
{
  if(this != &rhs)
  {
    if(!this -> isEmpty())
      this -> ClearQueue();

    this -> copy(rhs);
  }
  return *this;
} 

bool Queue::isEmpty()
{
  bool isEmpty = false;
  if(this -> head == NULL)
    isEmpty = true;

  return isEmpty;
}

int Queue::frontOfQueue()
{ 
  int frontNode;
  frontNode = this -> head -> data;     
  return frontNode;
}

void Queue::ClearQueue()
{
  while(!this -> isEmpty())
  {
    this -> Dequeue();
  }
}

void Queue::copy(const Queue &rhs)
{
  if(rhs.head == NULL)
  {
    this -> head = NULL;
    this -> tail = NULL;
  }
  else
  {
    //Node* curr = rhs.head -> next;
    //this -> Enqueue(rhs.head -> data);
    Node* curre = rhs.head;
    while(curre)
    {
      this -> Enqueue(curre -> data);
      curre = curre -> next;
    }
  }
}
