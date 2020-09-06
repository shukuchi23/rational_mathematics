//
// Created by admin on 05.09.2020.
//

#ifndef HYDRA_FRACTION_H
#define HYDRA_FRACTION_H
#include "abstr_digit.h"
#include "Double.h"
#include <iostream>
#include <memory>
#include "irracional.h"

class fraction : public abstr_digit {
public:
    
    fraction(abstr_digit* numerator, abstr_digit* denominator);
    
    fraction(const fraction& obj);
    
    fraction& operator =(const fraction& rht); // TODO:
    
    double calculate() const override;
    
    std::string to_string() const override;
    
    fraction* clone() const override;
    
    types getType() const override;
    
    explicit operator double();
    
    /*<TODO: ez>*/
    fraction& operator *=(const fraction&);
    
    fraction& operator *=(const class irracional&);
    
    fraction& operator *=(const Double&);
    
    fraction& operator /=(const fraction&);
    
    fraction& operator /=(const class irracional&);
    
    fraction& operator /=(const Double&);
    
    /*<TODO: medium*/
    fraction& operator +=(const fraction&);
    
    fraction& operator +=(const class irracional&);
    
    fraction& operator +=(const Double&);
    
    fraction& operator -=(const fraction&);
    
    fraction& operator -=(const class irracional&);
    
    fraction& operator -=(const Double&);
    
    /*<TODO: ez>*/
    friend fraction operator *(const fraction&, const fraction&);
    
    friend fraction operator *(const fraction&, const class irracional&);
    
    friend fraction operator *(const fraction&, const Double&);
    
    friend fraction operator /(const fraction&, const fraction&);
    
    friend fraction operator /(const fraction&, const class irracional&);
    
    friend fraction operator /(const fraction&, const Double&);
    
    /*<TODO: medium>*/
    friend fraction operator +(const fraction&, const class irracional&);
    
    friend fraction operator +(const fraction&, const Double&);
    
    friend fraction operator +(const fraction&, const fraction&);
    
    friend fraction operator -(const fraction&, const class irracional&);
    
    friend fraction operator -(const fraction&, const Double&);
    
    friend fraction operator -(const fraction&, const fraction&);
    
    /*<TODO: end>*/
    
    friend std::ostream& operator <<(std::ostream& os, fraction& fr) { return os << fr.to_string(); }
    
    ~fraction() override;

private:
    abstr_digit* m_numerator;
    abstr_digit* m_denominator;
};


#endif //HYDRA_FRACTION_H
