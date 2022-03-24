#ifndef SIMPLETOKENIZER_H
#define SIMPLETOKENIZER_H

#include "SLT/Tokenizer/Tokenizer.h"

namespace slt{
    class SimpleTokenizer : public Tokenizer
    {
        private:
            Reader *input;

        public:
            std::string separator=" \t\n\r";
            std::string escape="";
            std::string mescape="";
            std::string solo="";
            std::string iseparator="";
            std::string groupsolo="";

            SimpleTokenizer(Reader*);

            std::string next();
            bool hasnext();
    };
}
#endif // SIMPLETOKENIZER_H
