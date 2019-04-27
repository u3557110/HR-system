//
//  printRec.hpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#ifndef printRec_hpp
#define printRec_hpp

#include <stdio.h>
#include "structStaffRec.hpp"

// Function: print the content of the database
// Input: StaffRec database[]: the address pointing to the database
//        int number_of_records: number of records the database has
//        int records_per_page: number of records can be displayed each time
//        int n: page number
// Output: NULL
char print_table(StaffRec database[], int number_of_records, int records_per_page, int n);

// Function: sort the records in the database
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int capacity: size of the current database
//        int records_per_page: number of records can be displayed each time
// Output: NULL
void show_database(StaffRec * &database, int &number_of_records, int capacity, int records_per_page);

#endif /* printRec_hpp */
