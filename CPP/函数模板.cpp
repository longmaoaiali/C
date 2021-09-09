#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const& Max(T const& a,T const& b)
{

    return a<b? b:a;

}

int main()
{
    int i=3;
    int j=2;

    cout<<"int max is "<<Max(i,j)<<endl;

    double f1 = 0.5;
    double f2 = 1.3;
    cout<<"double max is "<<Max(f1,f2)<<endl;

    string s1 = "a";
    string s2 = "b";
    cout<<"string max is "<<Max(s1,s2)<<endl;

    char c1 = 'c';
    char c2 = 'd';
    cout<<"string max is "<<Max(c1,c2)<<endl;
    return 0;
}
