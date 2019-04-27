//
//  file.hpp
//  ENGG1340_course_project
//
//  Created by Leung King To on 27/4/2019.
//  Copyright © 2019 Leung King To. All rights reserved.
//

#ifndef file_hpp
#define file_hpp

#include <stdio.h>

#include <fstream>

#include "structStaffRec.hpp"

using namespace std;

// Function: export database to file
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int &capacity: the size of the current database
// Output: int: 0 = unsuccessful input. 1 = successful input.
int file_import(StaffRec * &database, int &number_of_records, int &capacity);

// Function: import database from file
// Input: StaffRec database[]: the address pointing to the database
//        int &number_of_records: number of records the database has
// Output: int: 0 = unsuccessful output. 1 = successful output.
int file_export(StaffRec database[], int number_of_records);

// Function: enlarge the database if it is too small to add new record
// Input: StaffRec * &database: the address pointing to the database
//        int &capacity: the size of the current database, before incrementation
//        int increment: size of the incrementation
// Output: NULL
void grow_array(StaffRec * &database, int &capacity, int increment);

#endif /* file_hpp */
