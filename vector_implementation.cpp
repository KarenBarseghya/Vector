#include <iostream>
template<typename T>
class Vector
{
    size_t cap;
    size_t size;
    T* buf;
public:
    Vector();
    Vector(size_t count , T value);
    Vector(size_t count);
    Vector(const Vector& other);
    Vector(Vector&& other);
    Vector(std::initializer_list<T> init_values);
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);
    void push_back(int value);
    size_t size_vec();
    size_t cap_vec();
    bool empty();
    void pop_back();
    void resize(size_t value);
    ~Vector();
    
};

int main()
{
    Vector<int> a;
    a.push_back(6);
    a.push_back(6);
    a.push_back(6);
    a.push_back(6);
    a.push_back(6);
    a.resize(6);

    std::cout << a.cap_vec();
   
}

template<typename T>
Vector<T>::Vector():cap{1} , size{} , buf{}
{}

template<typename T>
Vector<T>::Vector(size_t count , T value):cap{count} , size{count}
{
    buf = new T[cap];
    for(int i = 0 ; i < size ; ++i)
    {
        buf[i] = value;
    }
}

template<typename T>
Vector<T>::Vector(size_t count):cap{count},size{count}
{
    buf = new T[cap];
}

template<typename T>
Vector<T>::Vector(const Vector& other):cap{other.cap} , size{other.size},buf{}
{
    buf = new T[cap];
    for(int i = 0 ; i < size ; ++i)
    {
        cap[i] = other[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector&& other):cap{other.cap} , size{other.size} , buf{other.buf}
{
    other.cap = 0;
    other.size = 0;
    other.buf = 0;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> init_values) :cap{1} , size{0} , buf{}
{
    if(init_values.size())
    {
        cap = init_values.size();
        size = cap;
        buf = new T[cap];
        int j = 0;
        for(auto i = init_values.begin() ; i != init_values.end() ; ++i)
        {
            buf[j++] = *i; 
        }
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if(this != &other)
    {
        if(empty())
        {
            this -> size = other.size;
            this -> cap = other.cap;
            if(this -> buf)
            {
                this -> buf = new T[cap];
                for(int i = 0 ; i < this -> size;++i)
                {
                    this -> buf[i] = other.buf[i];
                }
            }
        }
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{
    this -> size = other.size;
    this -> cap = other.cap;
    T* ptr = this -> buf;
    this -> buf = other.buf;
    other.buf = ptr;
    ptr = nullptr;
}

template<typename T>
Vector<T>::~Vector()
{
    if(buf)
    {
        delete [] buf;
    }
}

template<typename T>
void Vector<T>::push_back(int value)
{
    ++size;
    if(!buf)
    {
        buf = new T;
    }
    if(size > cap)
    {
        cap *=2;
        T* new_arr = new T[cap];
        for(int i = 0 ; i < size ; ++i)
        {
            new_arr[i] = buf[i]; 
        }
        delete []buf;
        buf = new_arr;
        new_arr = nullptr;
    }
}

template<typename T>
void Vector<T>::pop_back()
{
    if(size > 0)
    {
        --size;
    }
    else
    {
        std::cout << "You can't go left there is no elements";
        exit(0);
    }
}

template<typename T>
void Vector<T>::resize(size_t value)
{
    if(value < 0)
    {
        std::cout << "Your vec size can't be -";
        exit(0);
    }
    else if(value > size)
    {
        cap = value;
    }
    else
    {
        cap = value;
        size = value;
    }
}


template <typename T>
bool Vector<T>::empty()
{
    if(size)
    {
        return true;
    }
    return false;
}

template<typename T>
size_t Vector<T>::size_vec()
{
    return size;
}

template<typename T>
size_t Vector<T>::cap_vec()
{
    return cap;
}







