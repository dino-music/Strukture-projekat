//Ina Saltovic
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "APIs.h"
#include <sstream>

bool isValid_mail(std::string mail);
bool isValid_jmbg(std::string jmbg);
//Harun Muderizovic
void SubjTeach(subjectapi&, teacherapi&, const std::string&);
void StudExams(studentapi&, const std::string&);
