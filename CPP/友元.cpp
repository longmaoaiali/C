#include <iostream>

using namespace std;

class Box{
private:
    double width;

public:
    void setWidth(double width){
        this->width = width;
    }

    friend void printWidth(Box box);
};

void printWidth(Box box){
    cout<<box.width<<endl;
}


int main(){
    Box box;

    box.setWidth(10.00);
    printWidth(box);

}
