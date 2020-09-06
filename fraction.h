//
// Created by admin on 05.09.2020.
//

#ifndef HYDRA_FRACTION_H
#define HYDRA_FRACTION_H
#include "abstr_digit.h"
#include <iostream>
#include <memory>

class fraction : public abstr_digit{
public:
    fraction(std::shared_ptr<abstr_digit> numerator, std::shared_ptr<abstr_digit> denominator);
    fraction(const fraction& obj);
    
    fraction& operator = (const fraction& rht);
    double calculate () const override;
    types getType() const override;
    
    explicit operator double();
    fraction& operator += (const abstr_digit*);
    friend fraction operator + (const fraction&, const abstr_digit*);
    
    fraction& operator -= (const abstr_digit*);
    friend fraction operator - (const fraction&, const abstr_digit*);
    
    fraction& operator *=(const abstr_digit*);
    friend fraction operator * (const fraction&, const abstr_digit*);
    
    fraction& operator /=(const abstr_digit*);
    friend fraction operator / (const fraction&, const abstr_digit*);
    
    friend std::ostream& operator << (std::ostream& os, const fraction& fr);
    
    
    ~fraction();
private:
    
    std::shared_ptr<abstr_digit> m_numerator;
    std::shared_ptr<abstr_digit> m_denominator;
};


#endif //HYDRA_FRACTION_H
