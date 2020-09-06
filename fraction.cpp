//
// Created by admin on 05.09.2020.
//

#include "fraction.h"
#include <assert.h>
#include <cmath>
#include <string>
fraction::fraction(std::shared_ptr<abstr_digit> numerator, std::shared_ptr<abstr_digit> denominator)
        : m_numerator(numerator), m_denominator(denominator)
{
    assert(m_numerator != nullptr
           && m_denominator != nullptr
           && fabs(m_denominator->calculate()) <=0.000000000001);
    
}

fraction::fraction(const fraction& obj) {

}


fraction& fraction::operator *=(const abstr_digit*) {}
fraction& fraction::operator -=(const abstr_digit*) {}
fraction& fraction::operator +=(const abstr_digit*) {}
fraction & fraction::operator /=(const abstr_digit*) {}
double fraction::calculate() const {
    return m_numerator->calculate() / m_denominator->calculate();
}
fraction::~fraction() {
    m_numerator.reset();
    m_denominator.reset();
}

std::ostream& operator <<(std::ostream& os, const fraction& fr)
{
    if (fr.m_numerator->getType() == abstr_digit::irracional
        && fr.m_denominator->getType() == abstr_digit::irracional )
        os << "#(" << fr.m_numerator << " / " << fr.m_denominator << ")";
    else
        if (fr.m_denominator->getType() == abstr_digit::irracional)
            os <<
    return os;
}

fraction& fraction::operator =(const fraction& rht)
{
    return ;
}

fraction operator +(const fraction&, const abstr_digit*)
{
    return fraction(nullptr, nullptr);
}

fraction operator -(const fraction&, const abstr_digit*)
{


}

fraction operator *(const fraction&, const abstr_digit*)
{
    return fraction(nullptr, nullptr);
}

fraction operator /(const fraction&, const abstr_digit*)
{
    return fraction(nullptr, nullptr);
}

abstr_digit::types fraction::getType() const
{
    return irracional;
}

fraction::operator double()
{
    return this->calculate();
}


