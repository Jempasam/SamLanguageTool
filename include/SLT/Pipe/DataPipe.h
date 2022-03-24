#ifndef DATAPIPE_H
#define DATAPIPE_H

template<typename T>
class DataPipe
{
    public:
        virtual T next()=0;
        virtual bool hasnext()=0;
};

#endif // DATAPIPE_H
