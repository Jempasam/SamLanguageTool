#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <typeinfo>
#include <typeindex>
#include <map>

class MultiParser
{
    private:
        std::map<std::type_index,void*(*)(std::string)> parser_map;
    public:

        void *_parse(std::type_index type, std::string text){
            return parser_map[type](text);
        }

        void _add(std::type_index type, void*(*parser)(std::string)){
            parser_map[type]=parser;
        }

        template<typename T>
        T parse(std::string text){
            T *ptr=reinterpret_cast<T*>(_parse(typeid(T),text));
            T ret=*ptr;
            delete ptr;
            return ret;
        }

        template<typename T>
        void add(T*(*parser)(std::string)){
            _add(typeid(T),reinterpret_cast<void*(*)(std::string)>(parser));
        }
};

#endif // PARSER_H
