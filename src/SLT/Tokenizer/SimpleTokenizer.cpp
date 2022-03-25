#include "SLT/Tokenizer/SimpleTokenizer.h"

bool contain(const std::string &str, const char &ch){
    return str.find(ch)!=-1;
}

slt::SimpleTokenizer::SimpleTokenizer(DataPipe<char>* input): input(input,5){
}

std::string slt::SimpleTokenizer::next(){
    std::string ret="";
    //Read
    char mesc=-1;
    char com=-1;
    char gsolo=-1;
    while(input.hasnext()){
        char ch=input.next();

        //Escape
        if(contain(escape,ch)){
            if(input.hasnext())ret+=input.next();
        }
        else if(mesc!=-1){
            if(ch==mesc)mesc=-1;
            else ret+=ch;
        }
        else if(contain(mescape,ch)){
            mesc=ch;
        }
        //Comment
        else if(com!=-1){
            if(ch==com)com=-1;
        }
        else if(contain(comment,ch)){
            com=ch;
        }
        //Separator
        else if(gsolo!=-1){
            if(ch==gsolo)ret+=ch;
            else{
                input.backward();
                break;
            }
        }
        else if(contain(groupsolo,ch)){
            if(ret.empty()){
                ret+=ch;
                gsolo=ch;
            }
            else{
                input.backward();
                break;
            }
        }
        else if(contain(solo,ch)){
            if(ret.empty()){
                ret+=ch;
                break;
            }
            else{
                input.backward();
                break;
            }
        }
        else if(contain(separator,ch)){
            if(!ret.empty())break;
        }
        else ret.push_back(ch);
    }

    //Clear after
    while(input.hasnext()){
        if(!contain(separator,input.next())){
            input.backward();
            break;
        }
    }

    //Return
    return ret;
}

bool slt::SimpleTokenizer::hasnext(){
    return input.hasnext();
}
