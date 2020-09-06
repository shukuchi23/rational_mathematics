//
// Created by admin on 05.09.2020.
//

#include "fraction.h"
#include <assert.h>
#include <cmath>
#include <string>
fraction::fraction(abstr_digit* numerator, abstr_digit* denominator)
        : m_numerator(numerator->clone()), m_denominator(denominator->clone())
{
    assert(m_numerator != nullptr
           && m_denominator != nullptr
           && fabs(m_denominator->calculate()) >= 0.000000000001);
}

fraction::fraction(const fraction& obj)
        : fraction(obj.m_numerator, obj.m_denominator) {}

double fraction::calculate() const
{
    return m_numerator->calculate() / m_denominator->calculate();
}

fraction::~fraction()
{
    delete m_numerator, m_denominator;
}

std::string fraction::to_string() const
{
    std::string str_fract = "(";
    str_fract
            .append(m_numerator->to_string())
            .append(") / (")
            .append(m_denominator->to_string())
            .append(")");
    return str_fract;
}


fraction& fraction::operator =(const fraction& rht)
{
//    TODO:
    return *this;
//    return ;
}

fraction operator -(const fraction& lft, const abstr_digit* rht)
{
    return fraction(nullptr, nullptr);
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
    return abstr_digit::fraction;
}

fraction::operator double()
{
    return this->calculate();
}


fraction* fraction::clone() const
{
    return new fraction(*this);
}

fraction operator +(const fraction& lft, const irracional& rht)
{
    return fraction(nullptr, nullptr);
}

fraction operator +(const fraction&, const Double&)
{
    return fraction(nullptr, nullptr);
}

fraction operator +(const fraction&, const fraction&)
{
    
    return fraction(nullptr, nullptr);
}

fraction operator *(const fraction&, const fraction&)
{
    
    return fraction();
}

fraction operator *(const fraction&, const irracional&)
{
    return fraction(nullptr, nullptr);
}

fraction operator *(const fraction&, const Double&)
{
    return fraction(nullptr, nullptr);
}

fraction& fraction::operator *=(const fraction& rht)
{
    return *this;
}

fraction& fraction::operator *=(const class irracional& rht)
{
//    TODO:
    return *this;
}

fraction operator /(const fraction&, const fraction&)
{
    return fraction(nullptr, nullptr);
}

fraction operator /(const fraction&, const irracional&)
{
    return fraction(nullptr, nullptr);
}

fraction operator /(const fraction&, const Double&)
{
    return fraction(nullptr, nullptr);
}

fraction operator -(const fraction&, const irracional&)
{
    return fraction(nullptr, nullptr);
}

fraction operator -(const fraction&, const Double&)
{
    return fraction(nullptr, nullptr);
}

fraction operator -(const fraction&, const fraction&)
{
    return fraction(nullptr, nullptr);
}

fraction& fraction::operator *=(const Double&)
{
    return <#initializer#>;
}

fraction& fraction::operator /=(const fraction&)
{
    return <#initializer#>;
}

fraction& fraction::operator /=(const class irracional&)
{
    return <#initializer#>;
}

fraction& fraction::operator /=(const Double&)
{
    return <#initializer#>;
}

fraction& fraction::operator +=(const fraction&)
{
    return <#initializer#>;
}

fraction& fraction::operator +=(const class irracional&)
{
    return <#initializer#>;
}

fraction& fraction::operator -=(const fraction&)
{
    return <#initializer#>;
}

fraction& fraction::operator -=(const class irracional&)
{
    return <#initializer#>;
}

fraction& fraction::operator -=(const Double&)
{
    return <#initializer#>;
}

fraction& fraction::operator +=(const Double&)
{
    return <#initializer#>;
}






