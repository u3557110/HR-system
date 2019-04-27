//
//  getAge.cpp
//  ENGG1340_course_project
//
//  Created by Leung King To on 27/4/2019.
//  Copyright © 2019 Leung King To. All rights reserved.
//

#include <ctime>

#include "getAge.hpp"

using namespace std;

int getAge(int birth_date, int birth_month, int birth_year){
    
    time_t current_time = time(0);
    tm* now = localtime(&current_time);
    
    int current_date = now -> tm_mday;
    int current_month = now -> tm_mon + 1;
    int current_year = now -> tm_year + 1900;
    
    // days of every month
    int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (birth_date > current_date) {
        current_date = current_date + month[birth_month - 1];
        current_month = current_month - 1;
    }
    
    if (birth_month > current_month) {
        current_year = current_year - 1;
        current_month = current_month + 12;
    }
    
    // calculate date, month, year
    // int calculated_date = current_date - birth_date;
    // int calculated_month = current_month - birth_month;
    int calculated_year = current_year - birth_year;
    
    return calculated_year;
}
