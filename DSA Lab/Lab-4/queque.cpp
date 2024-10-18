#include<bits/stdc++.h>
#define MAX 100
using namespace std;


class Queue{
    private:
        int front;
        int rear;
        int size;
        int queue[MAX];
    public:
        Queue() : front(0),rear(-1),size(0){
           
        }
        ~Queue(){
            // cout << "Destructor" << endl;
        }

        bool isFull(){
            return size == MAX;
        }
        bool isEmpty(){
            return size==0;
        }

        void enqueue(int el){
            if(isFull()) cout << "QUEUE IS FULL" << endl;
            else{
                 rear = (rear+1)%MAX;
                 queue[rear] = el;
                size++;
            }
        }

        void dequeue(){
            if(isEmpty()) cout << "Nothing to Delete. Already EMpty";
            else{
                int value = queue[front];
                front = (front+1)%MAX;
                size--;  
                cout <<  value <<" Deleted" <<endl;
            }
        }
        void front_back(int el){
            for(int i=size; i>=0; i--){
                queue[i+1] = queue[i];
            }
            queue[0] = el;
            size++;
        }

        void display(){
            if(isEmpty()) cout << "Empty Queue\n";
            else{
                int i = front;
                for(int c=0; c<size; c++){
                    cout << queue[i] << " ";
                    i = (i+1)%MAX;
                }
                cout << endl;
            }
        }


};



int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.display();
    q.front_back(1);
    q.display();
}