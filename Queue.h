/* This is the declaration of the Priority Queue Class using a Linked List
 * Author: Gino P. Corrales-Delgado
 * IT 279  -  9/28/2012
 */
#ifndef QUEUE_H
#define QUEUE_H

class Queue
{ 
  class Node
  {
    public:
      // Node constructor
      Node(int data, Node* next = NULL)
      {
        this -> data = data;
        this -> next = next;
      }

      // data of the node
      int data;
      // int priority;
      // pointer to the next node
      Node* next;  
  };
  
  public:
   
    // Default constructor
    Queue();
    
    // Copy constructor
    Queue(const Queue &orig);
    
    // Destructor
    ~Queue();
    
    // Inserts data in the queue
    //void Enqueue(int data[]);   
    void Enqueue(int min);
   
    // Removes from the queue
    void Dequeue();          
   
    // Overload Assign Operator
    Queue& operator=(const Queue &rhs); 

    // Verifies if Queue is empty
    bool isEmpty();

    // Shows what is at the front of the queue          
    int frontOfQueue();  												

  private:

    // Pointer to the head of the linked list
    Node* head;  

    // Pointer to the tail of the linked list      
    Node * tail;  

    // Cleans the Queueu
    void ClearQueue();    

    // Method used by the copy constructor
    void copy(const Queue &rhs);
};

#endif
