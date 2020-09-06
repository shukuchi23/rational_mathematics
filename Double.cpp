//
// Created by admin on 06.09.2020.
//

#include "Double.h"
#include <cmath>
double Double::eps = 0.00000000001;
Double::Double(double d) : m_value(d){}

double Double::calculate() const
{
    return m_value;
}

abstr_digit::types Double::getType() const
{
    return racional;
}

std::string Double::to_string() const
{
    return std::to_string(m_value);
}
//bool Double::operator ==(const Double& rhs) const
//{
//    return std::fabs(m_value - rhs.m_value) <= eps;
//}
//
//bool Double::operator !=(const Double& rhs) const
//{
//    return !(rhs == *this);
//}

Double operator +(Double lft, const std::shared_ptr<abstr_digit> rht)
{
    return lft.calculate() + rht->calculate();
}

Double operator -(Double lft, const std::shared_ptr<abstr_digit> rht)
{
    return lft.calculate() - rht->calculate();
}

Double operator *(Double lft, const std::shared_ptr<abstr_digit> rht)
{
    return lft.calculate() * rht->calculate();
}

Double operator /(Double lft, const std::shared_ptr<abstr_digit> rht)
{
    return lft.calculate() / rht->calculate();
}

Double& Double::operator +=(const std::shared_ptr<abstr_digit> rht)
{
    this->m_value += rht->calculate();
    return *this;
}

Double& Double::operator -=(const std::shared_ptr<abstr_digit> rht)
{
    this->m_value -= rht->calculate();
    return *this;
}

Double& Double::operator *=(const std::shared_ptr<abstr_digit> rht)
{
    this->m_value *= rht->calculate();
    return *this;
}

Double& Double::operator /=(const std::shared_ptr<abstr_digit> rht)
{
    this->m_value /= rht->calculate();
    return *this;
}

Double* Double::clone() const
{
    return new Double(*this);
}

Double::~Double() {}



//bool operator <(const Double& lhs, const Double& rhs)
//{
//    return std::isless(lhs.calculate(), rhs.calculate());
//}
//
//bool operator >(const Double& lhs, const Double& rhs)
//{
//    return rhs < lhs;
//}
//
//bool operator <=(const Double& lhs, const Double& rhs)
//{
//    return !(rhs < lhs);
//}
//
//bool operator >=(const Double& lhs, const Double& rhs)
//{
//    return !(lhs < rhs);
//}
