#include <iostream>

using namespace std;

class Box{
private:
    double length;
    double width;
    double height;

public:
    void setLength(double length){
        this->length = length;
    }

    void setHeight(double height){
        this->height = height;
    }

    void setWidth(double width){
        this->width = width;
    }

    double getVolum(void){
        return length*width*height;
    }

    Box operator+(const Box& b){
        Box box;

        box.length = this->length + b.length;
        box.height = this->height + b.height;
        box.width = this->width + b.width;

        return box;

    }

};

int main()
{
    Box box1;
    Box box2;
    Box box3;

    box1.setHeight(1.0);
    box1.setLength(1.0);
    box1.setWidth(1.0);

    box2.setHeight(1.0);
    box2.setLength(1.0);
    box2.setWidth(1.0);

    box3 = box1 + box2;

    cout<<"volum is "<<box3.getVolum()<<endl;
}
