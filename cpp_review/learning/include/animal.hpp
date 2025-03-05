//  Copyright (c) 2025. aaron.
//
//  This program is under the GPL-3.0 license.
//  if you have not received it or the program has several bugs, please let me know:
//  <communicate_aaron@outlook.com>.

//
// Created by aaron on 25-3-1.
//

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class ANIMAL {
public:
    std::string _name;
    int _age{ 0 };

    void sound() const;
    void eat() const;
};

#endif // ANIMAL_HPP
