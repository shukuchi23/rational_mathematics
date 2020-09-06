//
// Created by admin on 06.09.2020.
//

#ifndef HYDRA_IRRACIONAL_H
#define HYDRA_IRRACIONAL_H

#include "abstr_digit.h"
#include "fraction.h"
#include <string>
#include <iostream>
#include <exception>

const std::string root = "\u221A"; // символ корня

/*исключение: подкоренное выражение < 0*/
class subzeroException : public std::exception {
public:
    ~subzeroException() noexcept override;
    
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;
};

class irracional : public abstr_digit {
public:
    irracional(int irrational);
    
    irracional(int rational, int irrational);
    
    irracional(const std::string& exp);
    
    irracional(const irracional& obj);
    
    irracional& operator =(const irracional& rht);
    
    std::string to_string() const override;
    
    double calculate() const override
    {
        return (double) m_rational * sqrt(m_irrational);
    }
    
    irracional* clone() const override;
    
    types getType() const override
    {
        return types::irracional;
    }
    
    explicit operator double() const;
    
    bool operator ==(const irracional& rht) const;
    
    bool operator !=(const irracional& rht) const;
    
    irracional& operator *=(const irracional& rht);
    
    friend irracional operator *(irracional lft, const irracional& rht);
    
    irracional& operator /=(const irracional& rht);

//    friend bool operator <(const irracional& lhs, const irracional& rhs);
//
//    friend bool operator >(const irracional& lhs, const irracional& rhs);
//
//    friend bool operator <=(const irracional& lhs, const irracional& rhs);
//
//    friend bool operator >=(const irracional& lhs, const irracional& rhs);
    
    friend std::istream& operator >>(std::istream& is, irracional& obj)
    {
        std::string exp;
        is >> exp;
        irracional a(exp);
        obj.swap(a);
        return is;
    }
    
    friend std::ostream& operator <<(std::ostream& os, irracional& obj)
    {
        return os << obj.to_string();
    }
    
    ~irracional() override = default;

private:
    void swap(irracional& obj);
    
    void lick_balls();  //приведение подкоренного числа в
    //число,подкоренное число
private:
    int m_rational;     // целая часть ир.числа
    int m_irrational;   // иррациональная часть
};


#endif //HYDRA_IRRACIONAL_H
