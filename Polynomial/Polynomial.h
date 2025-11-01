#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <cstddef>
#include <iostream>
#include <string.h>

namespace Poly
{
    class Polynomial
    {
    private:
        class Ele
        {
        public:
            int k; //系数
            int exp;  //指数

            Ele(int ink = 0, int inexp = 0) : k(ink), exp(inexp) {}
        };

        class Node
        {
        public:
            Ele element; 
            Node * next = nullptr;

            Node(int ink = 0, int inexp = 0)
            {
                element.k = ink;
                element.exp = inexp;
                next = nullptr;
            }
        };
        
        int len;
        Node * head;
        Node * rear;
        //这里需要特别注意，迭代指针时不能直接迭代head，否则会导致头节点丢失
    
    public:
    //以下是类似于vector实现的指针迭代器
        class interator
        {
        public:
                Node * ptr;
            interator(Node * inptr) : ptr(inptr) {}

            interator & operator++()  //前置递增++a
            {
                if (ptr)
                    ptr = ptr->next;
                return *this;
            }
            interator operator++(int)  //加int是为了让编译器区分
            //                            前置与后置的递增
            {
                interator tmp = ptr;
                ++(*this);
                return tmp;
            }

            bool operator!=(const interator &other) const 
            {
            return ptr != other.ptr;
            }

            //解引用
            Ele & operator*() {return ptr->element;}
        };    

        // begin() / end() must be members of Polynomial (not the nested type),
        // because a nested class cannot access non-static members of the enclosing class.
        interator begin() const {return interator(head);}
        interator end() const {return interator(nullptr);}
        //迭代器至此结束

        Polynomial(int m);
        Polynomial(Node * h = nullptr, Node * r = nullptr, int l = 0) : head(h),
            rear(r), len(l) {}

        ~Polynomial();
        Polynomial(const Polynomial & copy);
        Polynomial & operator=(const Polynomial & ass);
        void sort_by_exp();

        int length() const {return len;}

        friend Polynomial operator+(const Polynomial & a, const Polynomial & b);
        //这里的返回值有问题
        //单个项加入的操作尚未重载
        friend Polynomial operator-(const Polynomial & a, const Polynomial & b);
        friend Polynomial operator*(const Polynomial & a, const Polynomial & b); //abstract
        friend std::ostream & operator<<(std::ostream & os, const Polynomial & p);
    };
} // namespace Poly

#endif