//
//  file.hpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#ifndef file_hpp
#define file_hpp

#include <stdio.h>

#include <iostream>
#include <fstream>

#include "structStaffRec.hpp"

using namespace std;

int file_import(StaffRec * &database, int &number_of_records, int &capacity);

int file_export(StaffRec database[], int number_of_records);

void grow_array(StaffRec * &database, int &capacity, int increment);

#endif /* file_hpp */
