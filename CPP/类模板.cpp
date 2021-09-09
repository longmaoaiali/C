#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

template <class T>
class Stack{
private:
    vector<T> items;
public:
    void push(T const& item);
    void pop();
    T const top();
    bool empty(){
        return items.empty();
    }
};


template <class T>
void Stack<T>::push(T const& item){
    items.push_back(item);
}

template <class T>
void Stack<T>::pop(){
    if(items.empty()){
        throw out_of_range("vector is empty, out of range");
    }
    items.pop_back();
}

template <class T>
T const Stack<T>::top(){

    if(items.empty()){
        throw out_of_range("vector is empty, out of range");
    }

    return items.back();
}

int main()
{
    try{
        Stack<int> intStack;
        Stack<string> stringStack;

        intStack.push(7);
        cout<<intStack.top()<<endl;

        stringStack.push("hello");
        cout<<stringStack.top()<<endl;

        stringStack.pop();
        stringStack.pop();//throw exception

    } catch(exception ex){
        cout<<"Exception is "<<ex.what()<<endl;
        return -1;
    }
    return 0;
}
