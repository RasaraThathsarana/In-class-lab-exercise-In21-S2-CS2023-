#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Stack{
    
   
public:
        int top;
        int size;
        int stack[10];
        Stack(){
            size =10;
            top = -1;
        }
        
        void push(int x){
            top = top +1;
            if(top > size){
                cout<<"Stack overflow"<<endl;
            }
            else{
                stack[top] = x;
            }
        }
        
        int pop(){
            if(top<0){
                cout<<"Stack Underflow"<<endl;
                exit(0);
            }
            else{
                top = top -1;
                return stack[top+1];
            }
        }
        
        bool isEmpty(){
            if(top<0){
                return true;
            }
            return false;
        }
        
        bool isFull(){
            if(top == size){
                return true;
            }
            return false;
        }
        
        void display(){
            if(top>=0){
                for(int i=top; i>=0; i--){
                    cout<<stack[i]<<" ";
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
