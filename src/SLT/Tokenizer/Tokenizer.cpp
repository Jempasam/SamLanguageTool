#include "Tokenizer.h"


std::vector<std::string> slt::Tokenizer::getAll(){
    std::vector<std::string> ret;
    while(hasnext()){
        ret.push_back(next());
    }
    return ret;
}
