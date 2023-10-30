#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>

class Array
{
public:
    Array<T>(void) : _ar(new T[0]), _size(0) {};
    
    ~Array<T>(void)
    {
        delete[] this->_ar;
    }

    Array<T>(unsigned int n)
    {
        _ar = new T[size];
    }

    Array<T>(Array<T> const &cp) : _size(cp._size)
    {
        _ar = new T[_size];
        for (unsigned int i = 0; i  < size; i++)
            _ar[i] = cp._ar[i];
    }

    Array<T> & operator=(Array<T> const &src)
    {
        if (&src == this)
            return (*this);
        _size = src._size;
        _ar = new T[src._size];
        for (unsigned int n = 0; n < _size; i++)
            _ar[i] = src._ar[i];
        return (*this);
    }

    T &operator[](const int i) const
    {
        if (i < 0 || static_cast<unsigned int>(i) >= _size)
            throw std::exeption()::what();
        return (_ar[i]);
    }


private:
    T *_ar;
    unsigned int _size;

};

#endif