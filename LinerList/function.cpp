#include "headerfile.h"
using std::cout;
using std::endl;
namespace LinerList
{
    List::List(int i)
    {
        baseArr = new int[i];
        quantity = i;
        used = 0;
    }
    List::List(int i, const int *in)
    {
        baseArr = new int[i];
        used = i;
        for (int n{}; n < i; n++)
            baseArr[n] = in[n];
    }
    List::~List()
    {
        delete[] baseArr;
    }

    bool List::add(int a)
    {
        if (is_full())
        {
            int *temp{baseArr};
            if (!(baseArr = new int[used + 1]))
            {
                cout << "No free space" << endl;
                return false;
            }
            for (int i{}; i < used; i++)
                baseArr[i] = temp[i];
            delete[] temp;
            quantity++;
        }
        if (baseArr)
        {
            baseArr[used] = a;
            used++;
            return true;
        }
        std::cout << "Error" << std::endl;
        return false;
    }

    bool List::del(int point)
    {
        if (used == 0 || point < 0 || point >= used)
        {
            cout << "Invalid delete position" << endl;
            return false;
        }
        for (int i = point; i < used - 1; i++)
            baseArr[i] = baseArr[i + 1];
        used--;
        return true;
    }

    int List::search(int k) const
    {
        bool flag{false};
        for (int i{}; i < used; i++)
        {
            if (baseArr[i] == k)
            {
                flag = true;
                return k;
            }
        }
        return 0;
    }
    bool List::modify(int point, int k)
    {
        if (point > used || point < 0)
        {
            cout << "Invalid data" << endl;
            return false;
        }
        baseArr[point] = k;
        return true;
    }

    bool List::insert(int a, int point)
    {
        if (is_full())
        {
            int *temp{baseArr};
            if (!(baseArr = new int[used + 1]))
            {
                cout << "No free space" << endl;
                return false;
            }
            for (int i{}; i < used; i++)
                baseArr[i] = temp[i];
            delete[] temp;
            quantity++;
        }
        if (point > used && point < 0)
            return false;
        for (int i{used - 1}; i >= point; i--)
            baseArr[i + 1] = baseArr[i];
        baseArr[point] = a;
        used++;
        return true;
    }

    List operator+(const List &a, const List &b)
    {
        List aandb(a.used + b.used);

        const int *p1 = a.baseArr;
        const int *p2 = b.baseArr;
        int *pRes = aandb.baseArr; // 指向结果表的开头

        unsigned int ua = a.used;
        unsigned int ub = b.used;

        while (ua > 0 && ub > 0)
        {
            if (*p1 <= *p2)
            {
                *pRes = *p1;
                ++p1;
                --ua;
            }
            else
            {
                *pRes = *p2;
                ++p2;
                --ub;
            }
            ++pRes;
            ++aandb.used;
        }

        while (ua > 0)
        {
            *pRes = *p1;
            ++p1;
            ++pRes;
            --ua;
            ++aandb.used;
        }

        while (ub > 0)
        {
            *pRes = *p2;
            ++p2;
            ++pRes;
            --ub;
            ++aandb.used;
        }

        return aandb;
    }

    std::ostream &operator<<(std::ostream &os, const List &L)
    {
        for (int i{}; i < L.used; i++)
        {
            os << L.baseArr[i] << "  ";
            if ((i + 1) % 5 == 0)
                cout << endl;
        }
        return os;
    }
}