#include "Polynomial.h"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

std::string superscript(int n);

namespace Poly
{
    Polynomial::Polynomial(int m) : len(m)
    {
        using std::cin;
        using std::cout;
        while (len <= 0)
        {
            cout << "Invalid length. Input again:";
            cin >> len;
        }
        

        for (int i{}; i < len; i++)
        {
            cout << "Please input the index: ";
            int k;
            cin >> k;
            while (k == 0)
            {
                cout << "Index can not be zero. Input again: ";
                cin >> k;
            }
            cout << "Now the exp: ";
            int exp;
            cin >> exp;
            Node *temp = new Node(k, exp);
            if (head == nullptr)
                head = temp;
            else
                rear->next = temp;
            rear = temp;
        }
        rear->next = nullptr;
        std::cout << "Build successfully!" << std::endl;
    }

    Polynomial::~Polynomial()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    // 一些思考：指针迭代器旨在访问数据时简化代码。然而该算法的大部分时候在新建链表
    // 所以使用迭代器并不能简化代码。
    Polynomial::Polynomial(const Polynomial &copy)
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        len = copy.len;
        Node *now = copy.head;

        for (int i{}; i < len; i++)
        {
            Node *temp = new Node(now->element.k, now->element.exp);
            if (head == nullptr)
                head = temp;
            else
                rear->next = temp;
            rear = temp;
            now = now->next;
        }
    }

    Polynomial &Polynomial::operator=(const Polynomial &rhs)
    {
        if (this == &rhs) // 处理自赋值
            return *this;

        // 清空原链表
        Node *cur = head;
        while (cur)
        {
            Node *temp = cur;
            cur = cur->next;
            delete temp;
        }

        head = nullptr;
        rear = nullptr;
        len = rhs.len;

        // 空表直接返回
        if (rhs.head == nullptr)
            return *this;

        // 深拷贝 rhs 的链表
        Node *src = rhs.head;
        while (src)
        {
            Node *node = new Node(src->element.k, src->element.exp);
            if (head == nullptr)
                head = node;
            else
                rear->next = node;
            rear = node;
            src = src->next;
        }
        rear->next = nullptr;
        return *this;
    }


    Polynomial operator+(const Polynomial &a, const Polynomial &b)
    {
        Polynomial::Node *head = nullptr;
        Polynomial::Node *rear = nullptr;
        int len = a.len + b.len;

        Polynomial::interator c(a.head);
        Polynomial::interator d(b.head);

        while (c.ptr != nullptr && d.ptr != nullptr)
        {
            Polynomial::Node *temp = new Polynomial::Node;
            if (c.ptr->element.exp < d.ptr->element.exp)
            {
                temp->element.exp = c.ptr->element.exp;
                temp->element.k = c.ptr->element.k;
                ++c;
            }
            else if (c.ptr->element.exp == d.ptr->element.exp)
            {
                if (c.ptr->element.k + d.ptr->element.k == 0)
                {
                    ++c;
                    ++d;
                    continue;
                }
                temp->element.exp = c.ptr->element.exp;
                temp->element.k = c.ptr->element.k + d.ptr->element.k;
                ++c;
                ++d;
            }
            else
            {
                temp->element.exp = d.ptr->element.exp;
                temp->element.k = d.ptr->element.k;
                ++d;
            }
            if (head == nullptr)
                head = temp;
            else
                rear->next = temp;
            rear = temp;
        } // Issue：这里其实可以用指针迭代器完成
        while (c.ptr != nullptr)
        {
            Polynomial::Node *ntemp = new Polynomial::Node;
            ntemp->element.exp = c.ptr->element.exp;
            ntemp->element.k = c.ptr->element.k;
            ++c;
            rear->next = ntemp;
            rear = ntemp;
        }
        while (d.ptr != nullptr)
        {
            Polynomial::Node *ntemp = new Polynomial::Node;
            ntemp->element.exp = d.ptr->element.exp;
            ntemp->element.k = d.ptr->element.k;
            ++d;
            rear->next = ntemp;
            rear = ntemp;
        }
        rear->next = nullptr;

        Polynomial Polytemp(head, rear, len);

        return Polytemp;
    } // 最后还要把rear.next做为空指针
 
    Polynomial operator-(const Polynomial &a, const Polynomial &b)
    {
        Polynomial::Node *head = nullptr;
        Polynomial::Node *rear = nullptr;
        int len = a.len + b.len;

        Polynomial::interator c(a.head);
        Polynomial::interator d(b.head);

        while (c.ptr != nullptr && d.ptr != nullptr)
        {
            Polynomial::Node *temp = new Polynomial::Node;
            if (c.ptr->element.exp < d.ptr->element.exp)
            {
                temp->element.exp = c.ptr->element.exp;
                temp->element.k = c.ptr->element.k;
                ++c;
            }
            else if (c.ptr->element.exp == d.ptr->element.exp)
            {
                if (c.ptr->element.k - d.ptr->element.k == 0)
                {
                    ++c;
                    ++d;
                    continue;
                }
                temp->element.exp = c.ptr->element.exp;
                temp->element.k = c.ptr->element.k - d.ptr->element.k;
                ++c;
                ++d;
            }
            else
            {
                temp->element.exp = d.ptr->element.exp;
                temp->element.k = -d.ptr->element.k;
                ++d;
            }
            if (head == nullptr)
                head = temp;
            else
                rear->next = temp;
            rear = temp;
        } // Issue：这里其实可以用指针迭代器完成
        while (c.ptr != nullptr)
        {
            Polynomial::Node *ntemp = new Polynomial::Node;
            ntemp->element.exp = c.ptr->element.exp;
            ntemp->element.k = c.ptr->element.k;
            ++c;
            rear->next = ntemp;
            rear = ntemp;
        }
        while (d.ptr != nullptr)
        {
            Polynomial::Node *ntemp = new Polynomial::Node;
            ntemp->element.exp = d.ptr->element.exp;
            ntemp->element.k = d.ptr->element.k;
            ++d;
            rear->next = ntemp;
            rear = ntemp;
        }
        rear->next = nullptr;

        Polynomial Polytemp(head, rear, len);

        return Polytemp;
    }

    // 先实现输出的重载以测试函数
    std::ostream &operator<<(std::ostream &os, const Polynomial &p)
    {
        using std::cout;
        using std::endl;
        if (p.head == nullptr)
        {
            cout << "Error! Empty List!" << endl;
            exit(1);
        } // 仍然是排错，后续可以删掉

        Polynomial::interator pt(p.head);
        int flag{1}; // 用于换行
        while (pt != p.end())
        {
            cout << " " << pt.ptr->element.k << '*';
            cout << "x" << superscript((*pt).exp) << " ";
            ++pt;
            if (pt != p.end() && pt.ptr->element.k < 0)
                cout << " ";
            if (pt != p.end() && pt.ptr->element.k > 0)
                cout << "+";
            if (flag % 4 == 0)
                cout << endl;
        }
        cout << endl
             << "That's it! " << endl;

        return os;
    }

    Polynomial operator*(const Polynomial & a, const Polynomial & b)
    {
        Polynomial sum;
        sum.head = nullptr;
        typedef Polynomial::Node PNode;
        Polynomial::interator nowa(a.head);
        for (int i{}; i < a.len; i++)
        {
            PNode * head = nullptr;
            PNode * rear = nullptr;
            Polynomial::interator nowb(b.head);

            for (int n{}; n < b.len; n++)
            {
                PNode * temp = new PNode;
                temp->element.k = (*nowb).k * (*nowa).k;
                temp->element.exp = (*nowb).exp + (*nowa).exp;
                if (head == nullptr)
                    head = temp;
                else
                    rear->next = temp;
                rear = temp;

                ++nowb;
            }
            rear->next = nullptr;
            Polynomial toadd(head, rear, b.len);
            if (sum.head == nullptr)
            {
                sum = toadd;
            }
            else
            {
                sum = sum + toadd;
            }
            ++nowa;
        }
        
        return sum;
    }

    void Polynomial::sort_by_exp()
    {
        if (head == nullptr || head->next == nullptr)
            return; // 空表或单节点不用排

        bool swapped;
        do
        {
            swapped = false;
            Node* prev = nullptr;
            Node* curr = head;

            while (curr->next != nullptr)
            {
                Node* next = curr->next;
                if (curr->element.exp > next->element.exp)
                {
                    // 交换节点（不是交换值）
                    swapped = true;

                    if (prev == nullptr)
                        head = next;
                    else
                        prev->next = next;

                    curr->next = next->next;
                    next->next = curr;

                    prev = next; // 注意 prev 更新
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
        } while (swapped);

        // 最后更新 rear
        rear = head;
        while (rear->next != nullptr)
            rear = rear->next;
    }
}

std::string superscript(int n)
{
    std::string normal = std::to_string(n);
    std::string result;

    for (char c : normal)
    {
        switch (c)
        {
        case '0': result += "⁰"; break;
        case '1': result += "¹"; break;
        case '2': result += "²"; break;
        case '3': result += "³"; break;
        case '4': result += "⁴"; break;
        case '5': result += "⁵"; break;
        case '6': result += "⁶"; break;
        case '7': result += "⁷"; break;
        case '8': result += "⁸"; break;
        case '9': result += "⁹"; break;
        default: result += c; break;
        }
    }

    return result;
}

