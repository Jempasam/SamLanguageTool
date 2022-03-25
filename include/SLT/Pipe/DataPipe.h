#ifndef DATAPIPE_H
#define DATAPIPE_H

namespace slt{
    template<typename T>
    class DataPipe
    {
        public:
            virtual T next()=0;
            virtual bool hasnext()=0;
    };

    template<typename F,typename T>
    using PipeFactory=DataPipe<T>*(*)(DataPipe<F>*);
}

#endif // DATAPIPE_H
