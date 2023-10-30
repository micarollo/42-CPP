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

    Array<T>(unsigned int n) : _size(n)
    {
        _ar = new T[n];
    }

    Array<T>(Array<T> const &cp) : _size(cp._size)
    {
        _ar = new T[_size];
        for (unsigned int i = 0; i  < _size; i++)
            _ar[i] = cp._ar[i];
    }

    Array<T> & operator=(Array<T> const &src)
    {
        if (&src == this)
            return (*this);
        delete[] _ar;
        _size = src.size();
        _ar = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _ar[i] = src._ar[i];
        return (*this);
    }

    T &operator[](const int i) const
    {
        if (i < 0 || static_cast<unsigned int>(i) >= _size)
            throw OutOfRange();
        return (_ar[i]);
    }

    class	OutOfRange : public std::exception
	{
	public:
		virtual const char *	what() const throw()
        {
            return ("Array index out of range");
        }
	};

    size_t size(void) const
    {
        return (this->_size);
    }


private:
    T *_ar;
    unsigned int _size;

};

#endif