#include <iostream>

#include <fstream>
#include <SLT/Reader.h>

using namespace std;

int main()
{
    std::ifstream file("test.txt");
    slt::InputStreamReader reader(&file);
    while(reader.hasnext()){
        char c=reader.next();
        reader.forward();
        std::cout<<"["<<c<<":"<<(int)c<<"]";
    }

    return 0;
}
