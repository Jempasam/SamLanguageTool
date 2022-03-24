#include <iostream>

#include <fstream>
#include <SLT/ReaderAndPipe.h>

using namespace std;

int main()
{
    std::ifstream file("test.txt");
    slt::InputStreamReader reader(&file);
    slt::BufferedDataPipe<char> pipe(&reader,10);
    while(pipe.hasnext()){
        char c=pipe.next();
        pipe.backward();
        std::cout<<"["<<c<<":"<<(int)c<<"]";
    }

    return 0;
}
