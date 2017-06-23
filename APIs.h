//Dino Music
#pragma once
#include "API.h"
#include "objekti.h"

class studentapi:public API<Student>
{

};

class teacherapi:public API<Teacher>
{

};

class subjectapi:public API<Subject>
{

};

class departmentapi:public API<Department>
{

};
