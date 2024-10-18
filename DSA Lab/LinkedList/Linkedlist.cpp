#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // int size = 0;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class LinkedList
{
    // Node *head
public:
    Node *head;
    int size = 0;
    LinkedList()
    {
        head = NULL;
        size;
    }
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        // NewNode Next Address is Current Head address
        newNode->next = head;
        // Move the head to point to the new node
        head = newNode;
        size++;
    }

    void insertAtTail(int val)
    {
        Node *temp = head;
        if (head == NULL)
        {
            insertAtHead(val);
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            Node *newNode = new Node(val);
            temp->next = newNode;
            size++;
        }
    }

    void insertAtIndex(int val, int indx){
        // Check for invalid index
        if (indx < 0 || indx > size){
            cout << "Invalid index" << endl;
            return;
        }
        // If inserting at head
        if (indx == 0){
            insertAtHead(val);
        }
        // If inserting at tail
        else if (indx == size){
            insertAtTail(val);
        }
        // Inserting at any other position
        else{
            Node *tmp = head;
            // Traverse to the (indx-1)th position (one before the insertion point)
            for (int i = 0; i < indx - 1; i++){
                tmp = tmp->next;
            }
            // Create the new node
            Node *newNode = new Node(val);
            // Insert the new node at the correct position
            newNode->next = tmp->next;
            tmp->next = newNode;       

            size++;
        }
    }

    void deleteAtHead(){
        if (head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        Node *tmp = head;
        head = tmp->next;
        size--;
    }

    void deleteAtTail(){
        // Check if the list is empty
        if (head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        else{
            Node *tmp = head;
            while(tmp->next->next != NULL){
                tmp = tmp->next;
            }
            delete tmp->next;
            tmp->next = NULL;
            size--;
        }
    }

    void deleteAtIndx(int idx){
        if(size==0){
            cout<<"List is Empty!" << endl;
            return;
        }
        else if(idx<0 || idx>=size){
            cout<<"Invalid Index" << endl;
            return;
        }
        else{
            if(idx == 0) deleteAtHead();
            else if(idx == size) deleteAtTail();
            else{
                Node *tmp = head;
                for(int i=0;i<idx-1;i++){
                    tmp = tmp->next;
                }
                tmp->next = tmp->next->next;
                size--;
            }
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertAtHead(1);  // Insert at Head
    list.insertAtHead(2);  // Insert at Head
    list.insertAtTail(5);  // Insert at Tail
    list.insertAtIndex(3,2); // Insert 5 at index 2 
    list.insertAtIndex(4,3); // Insert 4 at index 3
    list.display();          // Display
    
    list.deleteAtHead();    // delete a node from head
    list.display();         // Display

    list.deleteAtTail();    // Delete at Tail
    list.deleteAtIndx(1);   // Delete at Index 1
    list.display();         // Display
    list.insertAtIndex(9,10);     // Invalid Index

    list.display();         // Display the list
    
}