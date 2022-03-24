#include "SLT/Tokenizer/SimpleTokenizer.h"

bool contain(const std::string &str, const char &ch){
    return str.find(ch)!=-1;
}

slt::SimpleTokenizer::SimpleTokenizer(Reader* input){
    this->input=input;
}

std::string slt::SimpleTokenizer::next(){
    std::string ret="";
    while(input->hasnext()){
        char ch=input->next();
        if(contain(separator,ch)){

        }
        else ret.push_back(ch);
    }
}

bool slt::SimpleTokenizer::hasnext(){
}
