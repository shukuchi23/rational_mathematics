//
// Created by admin on 06.09.2020.
//

#ifndef HYDRA_IRRACIONAL_H
#define HYDRA_IRRACIONAL_H

#include "abstr_digit.h"
#include <string>
#include <iostream>
#include <cmath>
#include <exception>
const std::string root = "\u221A";
class subzeroException : public std::exception{
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
    irracional& operator = (const irracional& rht);
    
    double calculate() const override
    {
        return (double)m_rational * sqrt(m_irrational);
    }
    
    types getType() const override
    {
        return types::irracional;
    }
    
    operator double() const;
    bool operator == (const irracional& rht) const;
    bool operator != (const irracional& rht) const;
    
    irracional& operator *= (const irracional& rht);
    friend irracional operator * (irracional lft, const irracional& rht);
    irracional& operator /= (const irracional& rht);
    friend std::istream& operator >>(std::istream& is, irracional& obj)
    {
        std::string exp;
        is >> exp;
        irracional a(exp);
        obj.swap(a);
//        2#2 #12 12
        return is;
    }
    
    friend std::ostream& operator <<(std::ostream& os, const irracional& obj)
    {
        if (std::fabs(obj.m_rational) > 1)
            os << obj.m_rational;
        else
            if (obj.m_rational == -1)
                os << "-";
        
        if (obj.m_irrational > 1)
            os << root << obj.m_irrational;
        return os;
    }
    
    ~irracional() = default;
private:
    void swap(irracional& obj);
    void lick_balls();
private:
    int m_rational;
    int m_irrational;
};


#endif //HYDRA_IRRACIONAL_H
