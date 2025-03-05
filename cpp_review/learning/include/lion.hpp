//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

//
// Created by aaron on 25-3-1.
//

#ifndef LION_HPP
#define LION_HPP
#include "animal.hpp"

class Lion : public ANIMAL {
public:
    int _sleeping_time{ 0 };
    Lion();
    void hunting() const
    ;
};

#endif // LION_HPP
