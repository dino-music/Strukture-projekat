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
void SubjTeach(subjectapi&, teacherapi&, std::string);
void StudExams(studentapi&, subjectapi&, std::string);
//Vedad Mesic
void depSubRead(subjectapi&, departmentapi&, std::string);
void updateDepSub(subjectapi&);
void updateSubjTeach(subjectapi&);
void updateStudSubjTeach(studentapi&);
//Dino Music
void connect(studentapi&,teacherapi&,subjectapi&,departmentapi&);
