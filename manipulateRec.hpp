//
//  manipulateRec.hpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#ifndef manipulateRec_hpp
#define manipulateRec_hpp

#include <stdio.h>

#include "structStaffRec.hpp"

int add_record(StaffRec database[], int &number_of_records);

void edit_record(StaffRec database[], int index);

void delete_record(StaffRec * &database, int &number_of_records, int index, int capacity);

#endif /* manipulateRec_hpp */
