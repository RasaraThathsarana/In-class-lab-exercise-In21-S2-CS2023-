#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class node {
public:
    int data;
    node* ptr;
    
    node(int n)
    {
        this->data = n;
        this->ptr = NULL;
    }
};
  
class Stack {
    node* top;
  
public:
    Stack() { top = NULL; }
  
    void push(int data){
        node* temp = new node(data);
        if (!temp) {
            cout<<"Stack Overflow"<<endl;
        }
  
        temp->data = data;
        temp->ptr = top;
        top = temp;
    }
    
    void pop(){
        node* temp;
          if (top == NULL) {
            cout << "\nStack Underflow" << endl;
        }
        else {
            temp = top;
            top = top->ptr;
            free(temp);
        }
    }

    bool isEmpty(){
        return top == NULL;
    }
    int stackTop()
    {
        if (!isEmpty())
            return top->data;
        exit(0);
    }


    void display(){
        node* temp;
        if (top == NULL) {
            cout<<"Stack Underflow"<<endl;
        }
        else {
            temp = top;
            while (temp != NULL) {
                cout<<temp->data<<" ";
                temp = temp->ptr;
            }
            cout<<"\n";
        }
    }
};

int main() {
    auto start = high_resolution_clock::now();
    Stack s;

    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    for(int i=0; i<5;i++){
        s.pop();
    }
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken is: "<< duration.count() << " microseconds" << endl;
    return 0;
}