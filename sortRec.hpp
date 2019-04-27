//
//  sortRec.hpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#ifndef sortRec_hpp
#define sortRec_hpp

#include <stdio.h>

#include "structStaffRec.hpp"

// Function: sort the records in the database
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int capacity: size of the current database
// Output: NULL
void sort_record(StaffRec * &database, int &number_of_records, int capacity);

#endif /* sortRec_hpp */
