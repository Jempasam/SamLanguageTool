#ifndef SLT_TOKENIZER_TOKENIZER_H
#define SLT_TOKENIZER_TOKENIZER_H

#include "SLT/ReaderAndPipe.h"
#include <vector>

namespace slt{
    class Tokenizer : public DataPipe<std::string>
    {
        public:
            virtual std::string next()=0;
            virtual bool hasnext()=0;

            std::vector<std::string> getAll();
    };
    using TokenizerFactory=PipeFactory<char,std::string>;
}

#endif // SLT_TOKENIZER_TOKENIZER_H
