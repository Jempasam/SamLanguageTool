#ifndef READER_H
#define READER_H

#include <iostream>

namespace slt{
    class Reader
    {
        public:
            virtual char next()=0;
            virtual bool hasnext()=0;
            virtual void backward()=0;
            virtual void forward()=0;
    };
    using ReaderFactory=Reader*(*)(std::istream*);
}

#endif // READER_H
