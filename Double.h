//
// Created by admin on 06.09.2020.
//

#ifndef HYDRA_DOUBLE_H
#define HYDRA_DOUBLE_H

#include "abstr_digit.h"
#include <iostream>
/* вообще забей, хотя мб что-то найдешь*/

/*Класс обёртка под тип double*/
class Double : public abstr_digit {
public :
    static double eps;
    
    Double(double d);
    
    Double* clone() const override;

//    bool operator ==(const Double& rhs) const;
//    bool operator !=(const Double& rhs) const;
    
    
    /*мне похуй что ниже*/
    Double& operator +=(const std::shared_ptr<abstr_digit> rht);
    
    Double& operator -=(const std::shared_ptr<abstr_digit> rht);
    
    Double& operator *=(const std::shared_ptr<abstr_digit> rht);
    
    Double& operator /=(const std::shared_ptr<abstr_digit> rht);
    
    friend Double operator +(Double lft, const std::shared_ptr<abstr_digit> rht);
    
    friend Double operator -(Double lft, const std::shared_ptr<abstr_digit> rht);
    
    friend Double operator *(Double lft, const std::shared_ptr<abstr_digit> rht);
    
    friend Double operator /(Double lft, const std::shared_ptr<abstr_digit> rht);

//
//    friend bool operator <(const Double& lhs, const std::shared_ptr<abstr_digit> rhs);
//    friend bool operator >(const Double& lhs, const Double& rhs);
//    friend bool operator <=(const Double& lhs, const Double& rhs);
//    friend bool operator >=(const Double& lhs, const Double& rhs);
    std::string to_string() const override;
    
    friend std::ostream& operator <<(std::ostream& os, const Double& obj)
    {
        return os << obj.to_string();
    }
    
    friend std::istream& operator >>(std::istream& is, Double& obj)
    {
        return is >> obj.m_value;
    }
    
    double calculate() const override;
    
    types getType() const override;
    
    ~Double() override;
private:
    double m_value;
};


#endif //HYDRA_DOUBLE_H
