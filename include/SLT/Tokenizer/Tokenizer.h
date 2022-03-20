#ifndef SLT_TOKENIZER_TOKENIZER_H
#define SLT_TOKENIZER_TOKENIZER_H

#include "SLT/Reader/Reader.h"
#include <vector>

namespace slt{
    class Tokenizer
    {
        public:
            virtual std::string next()=0;
            virtual bool hasnext()=0;

            std::vector<std::string> getAll();
    };
    using TokenizerFactory=Tokenizer*(*)(Reader*);
}

#endif // SLT_TOKENIZER_TOKENIZER_H
