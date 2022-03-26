#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <vector>
#include <iostream>

template<typename T>
class ValueTreeNode;
template<typename T>
class ObjectTreeNode;

template<typename T>
class TreeNode
{
    private:
        std::string name;

    public:
        virtual bool isValue() const=0;
        virtual bool isObject() const=0;
        virtual ValueTreeNode<T> *asValue()=0;
        virtual ObjectTreeNode<T> *asObject()=0;

        std::string getName() const{
            return name;
        }

        void setName(std::string n) const{
            name=n;
        }

        virtual void toString(std::ostream& output) const=0;

        TreeNode(std::string n): name(n){
        }

        virtual ~TreeNode(){
        }
};
template<typename T>
std::ostream& operator <<(std::ostream& output, const TreeNode<T>& obj)
{
    obj.toString(output);
    return output;
}

template<typename T>
class ValueTreeNode : public TreeNode<T>
{
    private:
        T value;

    public:
        bool isValue()const override{ return true; }
        bool isObject()const override{ return false; }
        ValueTreeNode<T> *asValue()override{ return this; }
        ObjectTreeNode<T> *asObject()override{ return nullptr; }

        T getValue() const { return value; }
        void setValue(T v){ value=v; }

        void toString(std::ostream& output) const{
            output<<this->getName()<<":"<<getValue();
        }

        ValueTreeNode(std::string n, T v): TreeNode<T>(n), value(v){
        }
};

template<typename T>
class ObjectTreeNode : public TreeNode<T>
{
    private:
        std::vector<TreeNode<T>*> childs;

    public:
        bool isValue()const override{ return false; }
        bool isObject()const override{ return true; }
        ValueTreeNode<T> *asValue()override{ return nullptr; }
        ObjectTreeNode<T> *asObject()override{ return this; }

        const std::vector<TreeNode<T>*> &getChilds(){
            return childs;
        }

        int size() const{
            return childs.size();
        }

        TreeNode<T> *operator[](int index) const{
            return childs[index];
        }

        TreeNode<T> *get(std::string name) const{
            for(int i=0; i<childs.size(); i++){
                if(childs[i]->getName()==name){
                    return childs[i];
                }
            }
            return nullptr;
        }

        ValueTreeNode<T> *addValue(std::string n, T v){
            ValueTreeNode<T> *ret=new ValueTreeNode<T>(n,v);
            childs.push_back(ret);
            return ret;
        }

        ObjectTreeNode<T> *addObject(std::string n){
            ObjectTreeNode<T> *ret=new ObjectTreeNode<T>(n);
            childs.push_back(ret);
            return ret;
        }

        ObjectTreeNode(std::string n): TreeNode<T>(n){
        }

        void toString(std::ostream& output) const{
            output<<this->getName()<<":(";
            for(int i=0; i<size(); i++){
                if(i>0)output<<",";
                output<<*(*this)[i];
            }
            output<<")";
        }

        ~ObjectTreeNode(){
            for(unsigned int i=0; i<childs.size(); i++){
                delete childs[i];
            }
        }
};


#endif // TREENODE_H
