#ifndef INPUTSTREAMREADER_H
#define INPUTSTREAMREADER_H

#include "Reader.h"

namespace slt{
    class InputStreamReader : public Reader
    {
        private:
            std::istream *input;
            char n;
            char t;
        public:
            InputStreamReader(std::istream *input);
            char next();
            bool hasnext();
            void backward();
            void forward();
    };
}

#endif // INPUTSTREAMREADER_H
