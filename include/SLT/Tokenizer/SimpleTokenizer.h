#ifndef SIMPLETOKENIZER_H
#define SIMPLETOKENIZER_H

#include "SLT/Tokenizer/Tokenizer.h"

namespace slt{
    class SimpleTokenizer : public Tokenizer
    {
        private:
            BufferedDataPipe<char> input;

        public:
            std::string separator=" \t\n\r";
            std::string escape="";
            std::string mescape="";
            std::string solo="";
            std::string groupsolo="";
            std::string comment="";

            SimpleTokenizer(DataPipe<char>*);

            std::string next();
            bool hasnext();
    };
}
#endif // SIMPLETOKENIZER_H
