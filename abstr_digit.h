//
// Created by admin on 05.09.2020.
//

#ifndef HYDRA_ABSTR_DIGIT_H
#define HYDRA_ABSTR_DIGIT_H

struct abstr_digit {
    enum types {racional, irracional};
    
    virtual double  calculate () const = 0;
    virtual types getType() const  = 0;

};

#endif //HYDRA_ABSTR_DIGIT_H
