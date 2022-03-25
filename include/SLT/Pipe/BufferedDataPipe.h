#ifndef BUFFEREDDATAPIPE_H_INCLUDED
#define BUFFEREDDATAPIPE_H_INCLUDED

#include "DataPipe.h"

namespace slt{
    template<typename T>
    class BufferedDataPipe : public DataPipe<T>
    {
        private:
            DataPipe<T> *input;
            int buffersize;
            int bufferpos;
            int bufferhead;
            T *buffer;

        public:
            BufferedDataPipe(DataPipe<T> *input, int bufsize){
                this->input=input;
                this->buffer=new T[bufsize];
                this->buffersize=bufsize;
                this->bufferpos=-1;
                this->bufferhead=-1;
            }

            T next(){
                if(bufferpos==bufferhead){
                    bufferhead++;
                    if(bufferhead>=buffersize)bufferhead=0;
                    buffer[bufferhead]=input->next();
                }
                bufferpos++;
                if(bufferpos>=buffersize)bufferpos=0;
                return buffer[bufferpos];
            }

            bool hasnext(){
                return bufferpos!=bufferhead || input->hasnext();
            }

            void backward(){
                bufferpos--;
                if(bufferpos<0)bufferpos=buffersize-1;
            }

            void forward(){
                next();
            }

            ~BufferedDataPipe(){
                delete buffer;
            }
    };
}


#endif // BUFFEREDDATAPIPE_H_INCLUDED
