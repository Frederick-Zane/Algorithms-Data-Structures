#include <iostream>
typedef unsigned long Item;

class Stack
{
private:
    enum {Max = 10};
    Item * pitems;
    int size;
    int top;
public:
    Stack(int n = Max);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
    Stack & operator=(const Stack & st);
};

Stack::Stack(int n)
{
    pitems = new Item[n];
    size = n;
    top = 0;
}

Stack::Stack(const Stack & st)
{
    pitems = new Item[st.size];
    for (int i{}; i < st.size; i++)
        pitems[i] = st.pitems[i];
    size = st.size;
    top = st.top;
}

Stack::~Stack()
{
    delete [] pitems;   
}

bool Stack::isempty() const
{
    return (top == 0) ? true : false;
}

bool Stack::isfull() const
{
    return (top == size) ? true : false;
}

bool Stack::push(const Item & item)
{
    if (isfull())
    {
        std::cout << "Stack is full!" << std::endl;
        return false;
    }
    top++;
    pitems[top] = item;
    return true;
}

bool Stack::pop(Item & item)
{
    if (isempty())
    {
        std::cout << "Stack is empty!" << std::endl;
        return false;
    }
    item = pitems[top];
    pitems[top] = 0;
    top--;
    return true;
}

Stack & Stack::operator=(const Stack & st)
{
    if (this == &st)
        return *this;
    delete [] pitems;
    pitems = new Item[st.size];
    for (int i{}; i < st.size; i++)
        pitems[i] = st.pitems[i];
    top = st.top;
    size = st.size;
    return *this;
}