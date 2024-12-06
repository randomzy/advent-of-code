#ifndef UTILS_H_
#define UTILS_H_

#include <cassert>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

struct Index
{
    int row;
    int col;
    
    #define unary_op(op)                     \
    Index& operator op (const Index & o)     \
    {\
        row op o.row;\
        col op o.col;\
        return *this;\
    }
    unary_op(+=)
    unary_op(-=)
    unary_op(*=)
    #undef unary_op
};

#define binary_op(op)                                    \
inline Index operator op (const Index & a, const Index & b)     \
{return Index{a.row op b.row, a.col op b.col};}

binary_op(+)
binary_op(-)
binary_op(*)

#undef binary_op

inline bool operator==(const Index & a, const Index & b)
{
    return a.row == b.row && a.col == b.col;
} 


template<typename T>
class Matrix
{
public:
    Matrix<T>() = default;
    Matrix<T>(int rows, int cols, const T & val = T{}): rows(rows), cols(cols)
    {
        buff.resize(rows*cols, val);
    }

    T const & at(const Index & i) const {
        checkBounds(i);
        return buff[i.col + i.row * cols];
    }

    T & at(const Index & i) {
        checkBounds(i);
        return buff[i.col + i.row * cols];
    }

    int r() const {return rows;}
    int c() const {return cols;}
    void addRow(const std::vector<T> & row)
    {
        if(cols == 0)
        {
            cols = row.size();
        }
        buff.insert(buff.end(), row.begin(), row.end());
        rows++;
    }
    template<typename OT>
    friend Matrix<OT> readMatrix(std::istream &istr);
private:
    void checkBounds(const Index & i) const {
        if(i.col >= cols)
            throw std::out_of_range("");
        if(i.row >= rows)
            throw std::out_of_range("");
    }
    int rows = 0, cols = 0;
    std::vector<T> buff;
};


template<typename T>
std::ostream & operator << (std::ostream & os, const Matrix<T> & m)
{
    for(int r = 0; r < m.r(); r++)
    {
        std::string separator = "";
        for(int c = 0; c < m.c(); c++)
        {
            os << separator << m.at({r,c});
        }
        os << std::endl;
    }
    return os;
}

template<typename T>
Matrix<T> readMatrix(std::istream & istr, int padding = 0, T const & padding_value = T())
{
    Matrix<T> matrix;
    std::string tmpStr;
    while(std::getline(istr, tmpStr)) {
        std::stringstream ss(tmpStr);
        T a;
        std::vector<T> v;
        while(ss >> a) {
            v.push_back(a);
        }
        matrix.addRow(v);
    }
    return matrix;
}

#endif /* UTILS_H_ */
