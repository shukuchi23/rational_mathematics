//
// Created by admin on 06.09.2020.
//

#ifndef HYDRA_DOUBLE_H
#define HYDRA_DOUBLE_H

#include "abstr_digit.h"
#include <iostream>
class Double : public abstr_digit{
public :
    static double eps;
    Double(double d);
    
    bool operator ==(const Double& rhs) const;
    bool operator !=(const Double& rhs) const;
    
    Double& operator +=(const abstr_digit* rht);
    Double& operator -=(const abstr_digit* rht);
    Double& operator *=(const abstr_digit* rht);
    Double& operator /=(const abstr_digit* rht);
    friend Double operator + (Double lft,const abstr_digit* rht);
    friend Double operator - (Double lft,const abstr_digit* rht);
    friend Double operator * (Double lft,const abstr_digit* rht);
    friend Double operator / (Double lft,const abstr_digit* rht);
    
    friend bool operator <(const Double& lhs, const Double& rhs);
    friend bool operator >(const Double& lhs, const Double& rhs);
    friend bool operator <=(const Double& lhs, const Double& rhs);
    friend bool operator >=(const Double& lhs, const Double& rhs);
    
    friend std::ostream& operator << (std::ostream& os, const Double& obj) {
        return os << obj.m_value;
    }
    friend std::istream& operator >> (std::istream& is, Double& obj) {
        return is >> obj.m_value;
    }
    double calculate() const override;
    types getType() const override;
    
    ~Double() = default;
private:
    double m_value;
};


#endif //HYDRA_DOUBLE_H
