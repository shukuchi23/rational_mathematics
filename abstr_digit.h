//
// Created by admin on 05.09.2020.
//

#ifndef HYDRA_ABSTR_DIGIT_H
#define HYDRA_ABSTR_DIGIT_H

#include <cmath>
#include <memory>

struct abstr_digit {
    enum types { racional, irracional, fraction };
    
    /*каждый класс чисел может быть копирова*/
    virtual abstr_digit* clone() const = 0;
    
    /*какой тип у наследника abstr_digit?
     * types{ racional, irracional, fraction }*/
    virtual types getType() const = 0;
    
    /*каждый класс может быть красиво выведен*/
    virtual std::string to_string() const = 0;
    
    /*любой класс может вычислить своё значение*/
    virtual double calculate() const = 0;
    
    virtual ~abstr_digit() = default;
    
    virtual bool operator <(std::shared_ptr<abstr_digit> a)
    {
        return std::isless(calculate(), a->calculate());
    }
    
    virtual bool operator >(std::shared_ptr<abstr_digit> a)
    {
        return std::isless(a->calculate(), calculate());
    }
    
    virtual bool operator <=(std::shared_ptr<abstr_digit> a)
    {
        return std::islessequal(calculate(), a->calculate());
    }
    
    virtual bool operator >=(std::shared_ptr<abstr_digit> a)
    {
        return !std::isless(calculate(), a->calculate());
    }
    
    virtual bool operator ==(std::shared_ptr<abstr_digit> a)
    {
        return operator <=(a) && operator >=(a);
    }
    
    virtual bool operator !=(std::shared_ptr<abstr_digit> a)
    {
        return !operator ==(a);
    }
};


#endif //HYDRA_ABSTR_DIGIT_H
