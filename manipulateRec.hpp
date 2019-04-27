//
//  manipulateRec.hpp
//  ENGG1340_course_project
//
//  Created by Leung King To on 27/4/2019.
//  Copyright © 2019 Leung King To. All rights reserved.
//

#ifndef manipulateRec_hpp
#define manipulateRec_hpp

#include <stdio.h>

#include "structStaffRec.hpp"

// Function: add record to database
// Input: StaffRec database[]: the address pointing to the database
//        int &number_of_records: number of records the database has
// Output: int: 0 = unsuccessful adding. 1 = successful adding.
int add_record(StaffRec database[], int &number_of_records);

// Function: edit record in database
// Input: StaffRec database[]: the address pointing to the database
//        int index: the index, used in array, of the element going to be edited
// Output: NULL
void edit_record(StaffRec database[], int index);

// Function: delete record from databse
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int index: the index, used in array, of the element going to be deleted
//        int capacity: the capacity of the current database
// Output: NULL
void delete_record(StaffRec * &database, int &number_of_records, int index, int capacity);

#endif /* manipulateRec_hpp */
