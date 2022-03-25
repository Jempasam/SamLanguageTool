#include <iostream>

#include <fstream>
#include <SLT/ReaderAndPipe.h>
#include <SLT/Tokenizer.h>

using namespace std;

int main()
{
    std::ifstream file("test.txt");
    slt::InputStreamReader reader(&file);
    slt::SimpleTokenizer tokenizer(&reader);
    tokenizer.escape="\\";
    tokenizer.mescape="\"'`";
    tokenizer.solo="?.!";
    tokenizer.comment="#";
    tokenizer.groupsolo="&-";

    while(tokenizer.hasnext()){
        std::cout<<"["<<tokenizer.next()<<"] ";
    }

    return 0;
}
