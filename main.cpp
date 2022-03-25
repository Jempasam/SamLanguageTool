#include <iostream>

#include <fstream>
#include <SLT/ReaderAndPipe.h>
#include <SLT/Tokenizer.h>
#include <SLT/Tree/TreeNode.h>

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

    std::cout<<std::endl;

    ObjectTreeNode<std::string> o("France");
    o.addValue("type","pays");
    ObjectTreeNode<std::string> *sub=o.addObject("PACA");
    sub->addValue("type","region");
    sub->addValue("largename","Provence Alpes Cote D'Azur");

    std::cout<<o;

    return 0;
}
