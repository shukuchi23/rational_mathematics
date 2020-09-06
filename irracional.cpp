//
// Created by admin on 06.09.2020.
//

#include "irracional.h"
#include <algorithm>

irracional::irracional(int irrational)
        : m_rational(1), m_irrational(irrational)
{
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
