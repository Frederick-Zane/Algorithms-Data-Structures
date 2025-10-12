#ifndef HEADERFILE_H_
#define HEADERFILE_H_
#include <iostream>
namespace LinerList
{
    class List
    {
    private:
        const int MAX{50};
        int quantity{20};
        int used{0};
        int * baseArr;
        int n_add;
        int mul_n;
    public:
        List(int i = 20);
        List(int i, const int * in);
        ~List();
        bool add(int a);
        bool del(int point);
        int search(int k) const;
        bool modify(int point, int k);
        bool insert(int a, int point);
        friend List operator+(const List & a, const List & b);
        friend std::ostream & operator<<(std::ostream & os, const List & L);   
        int show_n() {return quantity;}
        bool is_full() {return used == quantity ? true : false;}
        bool is_empty() {return used == 0 ? true : false;}
    };
    
    
} // namespace LinerList

#endif