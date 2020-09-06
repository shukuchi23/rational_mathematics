//
// Created by admin on 06.09.2020.
//

#include "irracional.h"
#include <cstring>
#include <cmath>
irracional::irracional(int irrational)
        : m_rational(1), m_irrational(irrational)
{
    if (irrational < 0)
        throw subzeroException();
    if (irrational == 0) {m_rational = 0, m_irrational=1;}
    else
        lick_balls();
}

irracional::irracional(int rational, int irrational)
        : m_rational(rational), m_irrational(irrational) {
    lick_balls();
}

irracional::irracional(const std::string& exp)
{
    size_t root_pos = exp.find('#');
    m_rational = (root_pos > 0) ?
                 atoi(exp.substr(0, root_pos).c_str())
                                : 1;
    m_irrational = atoi(exp.substr(root_pos + 1).c_str());
    
    lick_balls();
}

irracional::irracional(const irracional& obj)
        : irracional(obj.m_rational, obj.m_irrational) {}

irracional& irracional::operator =(const irracional& rht)
{
    if (&rht != this)
    {
        irracional a(rht);
        this->swap(a);
    }
    return *this;
}

irracional::operator double() const
{
    return calculate();
}

bool irracional::operator ==(const irracional& rht) const
{
    return m_irrational == rht.m_irrational
           && m_rational == rht.m_rational;
}

bool irracional::operator !=(const irracional& rht) const
{
    return !(*this == rht);
}

irracional& irracional::operator *=(const irracional& rht)
{
    m_rational *= rht.m_rational;
    m_irrational *= rht.m_irrational;
    lick_balls();
    return *this;
}

irracional& irracional::operator /=(const irracional& rht)
{
    std::cout << "POSOSI( DELENIE )\n";
    return *this;
}

void irracional::swap(irracional& obj)
{
    std::swap(m_rational, obj.m_rational);
    std::swap(m_irrational, obj.m_irrational);
}

void irracional::lick_balls()
{
    int square = 4;
    for (int base = 2; square <= m_irrational; ++base, square = base * base) {
        if (m_irrational % square == 0) {
            m_rational *= base;
            m_irrational /= square;
        }
    }
}

irracional operator *(irracional lft, const irracional& rht)
{
    lft *= rht;
    return lft;
}

irracional* irracional::clone() const
{
    return new irracional(*this);
}

std::string irracional::to_string() const
{
    std::string ir_str = "";
    if (std::fabs(m_rational) > 1)
        ir_str += std::to_string(m_rational);
    else if (m_rational == -1)
        ir_str += "-";
    
    if (m_irrational > 1)
        ir_str.append(root).append(std::to_string(m_irrational));
    return ir_str;
}

//irracional::~irracional()
//{}

//bool operator <(const irracional& lhs, const abstr_digit* rhs)
//{
//    return std::isless(lhs.calculate(), rhs->calculate());
//}
//
//bool operator >(const irracional& lhs, const abstr_digit* rhs)
//{
//    return std::isless(rhs->calculate(), lhs.calculate());
//}
//
//bool operator <=(const irracional& lhs, const abstr_digit* rhs)
//{
//    return std::islessequal(lhs.calculate(), rhs->calculate());
//}
//
//bool operator >=(const irracional& lhs, const abstr_digit* rhs)
//{
//    return !std::isless(lhs.calculate(), rhs->calculate());
//
//}

subzeroException::~subzeroException() noexcept {}

const char* subzeroException::what() const noexcept
{
    return "Negative value under the root\n";
}
