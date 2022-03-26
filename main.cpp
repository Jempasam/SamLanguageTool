#include <iostream>

#include <fstream>
#include <SLT/ReaderAndPipe.h>
#include <SLT/Tokenizer.h>
#include <SLT/Tree/TreeNode.h>
#include <SLT/Parser/Parser.h>
#include <stdlib.h>

using namespace std;

int main()
{
    MultiParser pars;

    pars.add<int>([](std::string str){
        int *ret=new int;
        *ret=atoi(str.c_str());
        return ret;
    });

    pars.add<bool>([](std::string str){
        bool *ret=new bool;
        *ret=str!="false";
        return ret;
    });

    std::cout<<pars.parse<int>("0")<<std::endl;
    std::cout<<pars.parse<bool>("false")<<std::endl;

    return 0;
}
