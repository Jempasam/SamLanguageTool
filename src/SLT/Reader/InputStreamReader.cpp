#include "SLT/Reader/InputStreamReader.h"

slt::InputStreamReader::InputStreamReader(std::istream *input): input(input){
    n=input->get();
}

char slt::InputStreamReader::next(){
    t=n;
    n=input->get();
    return t;
}

bool slt::InputStreamReader::hasnext(){
    return n!=-1;
}

void slt::InputStreamReader::backward(){
    input->clear();
    input->unget();
    input->unget();
    n=input->get();
}

void slt::InputStreamReader::forward(){
    n=input->get();
}
