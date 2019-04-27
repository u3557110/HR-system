<h1 align="center">
	<img
		width="650"
		alt="Staff Management System"
		src="/LOGO.PNG">
</h1>

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/powered-by-oxygen.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/powered-by-water.svg)](https://forthebadge.com)

## Basic Overview
Many of the Staff Management Systems on the market is not free of charge. This obstructs the use of such systems in small and medium enterprises (SMEs), as resources of these companies are relatively constraints. To solve this, a compact open-source staff management system is being devloped. It is free of charge, and it allows everyone to extend its features. The system is easy to use, any kind of company will manage to use it. 

## Features
The staff management system is used to gather and manage the information about the employees of a company, which allows customized feature(s) by the client. 

### Searching for Employee(s)
Record of employee(s) can be searched by defining the search criteria. The criteria include, but is not limited to, the staff number, name, gender, age, job title, telephone number, living district, date of birth, I.D. number, bank account number, range of salary, form of employment (full time / part time), job status (on leave / suspension from work), etc.

### Create Record for New Employee(s)
For new employee, corresponding record can be created by providing the staff number, name, age, job title, and salary.

### Manipulate the Information of Employee(s)
Information of the existing workers can be modified. In case of being fired, records of employee can be deleted or moved to a separate place. A termination letter can also be generated accordingly. Moreover, self-defined attributes can also be added. 

### Import/Export the Information of Employee(s)
The programme can import the information of employee from text files. Also, the user can export the data for backup purpose.

### Show the Attendance and Leave of Employee(s)
The system can show the attendance and leave record of employee. 
It can also show the remaining days of Annaul Leave a employee owns. 
annual leave can be carried forward to the next year.

## Highlights
This system is useful because it can facilitate the managing work of human resources. Searching workers by different attributes such as ages, salary, roles can help to specify a certain group of workers. 

The information of the employees working on the same project can also be obtained for futher evaluation. For example, to determine whether there are too much manpower on a project. Workers can be diverted to other project which is lack of manpower and optimize the usage of labours.

Adding self-defined attributes enable the staff management system can work smoothly on different types of workers, companies and industries. The adding and deleting function can help to update the records of workers in real time. Exporting the information of workers out can help to save the information for backup purpose.

## Geting Started
Once the system is installed, information of workers can then be input to the system. Noted that to create a record successfully one must provide the staff number, name. For othere attributes, default values are being applied if they are not specified. The information can be altered or manipulated in future if necessary.

Note to Existing Users: After installation, the system can be started by importing the backup file. 

## Assistance for user(s)
A video of how to set up a file of a worker and an example of a finalised worker file will be provided in order to help the user to get used to the programme as soon as possible.

## Further Development
- Tax calculation for each employee.
- Show probation period.
- Show expiry date of related docunments, such as work permits, Visa and contracts. 

## Instruction
### Main Menu
```
  _, ___  _, __, __,   _, _  _, _, _  _,  _, __, _, _ __, _, _ ___    _, , _  _, ___ __, _, _
 (_   |  /_\ |_  |_    |\/| /_\ |\ | /_\ / _ |_  |\/| |_  |\ |  |    (_  \ | (_   |  |_  |\/|
 , )  |  | | |   |     |  | | | | \| | | \ / |   |  | |   | \|  |    , )  \| , )  |  |   |  |
  ~   ~  ~ ~ ~   ~     ~  ~ ~ ~ ~  ~ ~ ~  ~  ~~~ ~  ~ ~~~ ~  ~  ~     ~    )  ~   ~  ~~~ ~  ~
                                                                          ~'                 
==================================================================================================

¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
||			1. Import Record                                                        ||
||			2. Show Record                                                          ||
||			3. Add Record                                                           ||
||			4. Export Record                                                        ||
||			5. Search Record                                                        ||
||			6. Sort Record                                                          ||
||			7. Setting                                                              ||
||			0. Exit                                                                 ||
__________________________________________________________________________________________________

			Enter Choice: 
```

* Import Record = import records from file
### Add Record
```
Please enter Employee ID: 00000088			//should be in eight digits
Please enter First Name: Siu Hau				
Please enter Last Name: Chiu					
Please enter Gender: M					//should enter either 'M' or 'F'
Please enter Job Title: Engineer				
Please enter Salary: 30000					
Please enter Form of Employment: FT			//should enter either 'FT' or 'PT'
Please enter Job Status: Normal				//should enter either 'Normal' or 'Fired'
Please enter Phone Number: 56307923			//should be in eight digits 
Please enter Date of Birth (dd-mm-yyyy): 10-10-1993	//should follow the format dd-mm-yyyy
Add user defined attributes (Y/N)? N			//should enter either 'Y' or 'N'
```
### Show Record
```
Page: 1/3
 # Employee ID  First Name  Surname  Gender  Job Title   Salary  Form   Status  Phone No.  Date of Birth  Age
-------------------------------------------------------------------------------------------------------------
 1    00000001   Shun Wing     Wong       M        CEO   100000    FT   Normal  2233-3322     12-04-1978   41
 2    00000002     King To    Leung       M        CTO    90000    FT   Normal  6290-2718     03-04-1988   31
 3    00000003   Hing Wong     Chan       M        CFO    90000    FT   Normal  6663-6635     03-04-1982   37
 4    00000004     Sze Tat     Chau       M   Director    80000    FT   Normal  6031-0528     03-04-1988   31
 5    00000005    Bean Y C       Ho       M   Director    80000    FT   Normal  6354-7192     03-04-1984   35
 6    00000006       Doris       Lo       F        SVP    70000    FT   Normal  6988-5676     03-04-1988   31
 7    00000007        Hyde     Hang       M        SVP    70000    FT   Normal  6514-8946     03-04-1985   34
 8    00000008     Tai Man     Chau       M         VP    60000    FT   Normal  6401-4257     03-04-1988   31
 9    00000009    Siu Ming     Chan       M    Manager    50000    FT   Normal  6663-6568     03-04-1978   41
10    00000010     Sui Kit       Au       M    Manager    50000    FT   Normal  6830-0945     03-04-1968   51

Q = Quit. E = Edit. N = Next. P = Previous. D = Delete. S = Sort. F = Fire. Your Choce: 
```
### Edit Record
```
Which item you want to edit: 1
Current Employee ID = 00000001, New Employee ID (Press Enter if No Change): 00000888
Current First Name = Shun Wing, New First Name (Press Enter if No Change): 
Current Surname = Wong, New Surname (Press Enter if No Change): 
Current Gender = M, New Gender (Press Enter if No Change): 
Current Job Title = CEO, New Job Title (Press Enter if No Change): 
Current Salary = 100000, New Salary (Press Enter if No Change): 200000
Current Employment Form = FT, New Employment Form (Press Enter if No Change): PT
Current Status = Normal, New Status (Press Enter if No Change): 
Current Phone No. = 22333322, New Phone No. (Press Enter if No Change): 92347589
Current Date of Birth = 12-04-1978, New Date of Birth, dd-mm-yyyy (Press Enter if No Change): 

Page: 1/3
 # Employee ID  First Name  Surname  Gender  Job Title   Salary  Form   Status  Phone No.  Date of Birth  Age
-------------------------------------------------------------------------------------------------------------
 1    00000888   Shun Wing     Wong       M        CEO   200000    PT   Normal  9234-7589     12-04-1978   41
 2    00000002     King To    Leung       M        CTO    90000    FT   Normal  6290-2718     03-04-1988   31
 .
 .
 10   00000010     Sui Kit       Au       M    Manager    50000    FT   Normal  6830-0945     03-04-1968   51

Q = Quit. E = Edit. N = Next. P = Previous. D = Delete. S = Sort. F = Fire. Your Choce: 
```
### Delete Record
```
Which item you want to delete: 1
System Message: Item with ID = 00000888 is deleted!

Page: 1/3
 # Employee ID  First Name  Surname  Gender  Job Title   Salary  Form   Status  Phone No.  Date of Birth  Age
-------------------------------------------------------------------------------------------------------------
 1    00000002     King To    Leung       M        CTO    90000    FT   Normal  6290-2718     03-04-1988   31
 2    00000003   Hing Wong     Chan       M        CFO    90000    FT   Normal  6663-6635     03-04-1982   37
 .
 .
10    00000011    Hoi Wing      Liu       F    Manager    50000    FT   Normal  9371-0992     03-04-1948   71

Q = Quit. E = Edit. N = Next. P = Previous. D = Delete. S = Sort. F = Fire. Your Choce: 
```
### Fire an Employee
```
Whom you want to fire: 1
Page: 1/3
 # Employee ID  First Name  Surname  Gender  Job Title   Salary  Form   Status  Phone No.  Date of Birth  Age
-------------------------------------------------------------------------------------------------------------
 1    00000002     King To    Leung       M        CTO    90000    FT    Fired  6290-2718     03-04-1988   31
 2    00000003   Hing Wong     Chan       M        CFO    90000    FT   Normal  6663-6635     03-04-1982   37
 .
 .
 10   00000011    Hoi Wing      Liu       F    Manager    50000    FT   Normal  9371-0992     03-04-1948   71

Q = Quit. E = Edit. N = Next. P = Previous. D = Delete. S = Sort. F = Fire. Your Choce: 
```
### Search Record
```
Search/Delete Mode

1. Employee ID				//enter specific employee ID to search
2. Name					//enter last name or first name or both to search
3. Age					//enter the range of age to search
4. Role					//enter specific job title to search
Q. Quit					//quit

Please enter your choice: 2

Enter Employee First Name (Press Enter if not specified): 

Enter Employee Last Name (Press Enter if not specified): Chau

Page: 1/1
 # Employee ID  First Name  Surname  Gender  Job Title   Salary  Form   Status  Phone No.  Date of Birth  Age
-------------------------------------------------------------------------------------------------------------
 1    00000004     Sze Tat     Chau       M   Director    80000    FT   Normal  6031-0528     03-04-1988   31
 2    00000008     Tai Man     Chau       M         VP    60000    FT   Normal  6401-4257     03-04-1988   31

Q = Quit. E = Edit. N = Next. P = Previous. D = Delete. S = Sort. F = Fire. Your Choce: 
```

### Delete Records Being Searched
```
Which item you want to delete (input 'a' for all): a
System Message: Item with ID = 00000004 is deleted!
System Message: Item with ID = 00000008 is deleted!
.
.
Page: 1/3
 # Employee ID  First Name  Surname  Gender  Job Title   Salary  Form   Status  Phone No.  Date of Birth  Age
-------------------------------------------------------------------------------------------------------------
 1    00000002     King To    Leung       M        CTO    90000    FT    Fired  6290-2718     03-04-1988   31
 2    00000003   Hing Wong     Chan       M        CFO    90000    FT   Normal  6663-6635     03-04-1982   37
 3    00000005    Bean Y C       Ho       M   Director    80000    FT   Normal  6354-7192     03-04-1984   35
 4    00000006       Doris       Lo       F        SVP    70000    FT   Normal  6988-5676     03-04-1988   31
 5    00000007        Hyde     Hang       M        SVP    70000    FT   Normal  6514-8946     03-04-1985   34
 6    00000009    Siu Ming     Chan       M    Manager    50000    FT   Normal  6663-6568     03-04-1978   41
 7    00000010     Sui Kit       Au       M    Manager    50000    FT   Normal  6830-0945     03-04-1968   51
 8    00000011    Hoi Wing      Liu       F    Manager    50000    FT   Normal  9371-0992     03-04-1948   71
 9    00000012   Johnathan     Kwan       M Supervisor    40000    FT   Normal  9021-8501     03-04-1978   41
10    00000013        Zany       Ho       M Supervisor    40000    FT   Normal  9405-6602     03-04-1958   61
```
### Sort Record
```
Select attributes to sort:

1. Employee ID
2. First Name
3. Surname
4. Gender
5. Job Title
6. Salary
7. Form
8. Status
9. Phone No.
10. Date of Birth
11. Age

Please enter your choice: 
```
### Import Records from File
```
Please enter name of file to import: test.txt
System Message: Capacity of database has been enlarged to 6!
System Message: Capacity of database has been enlarged to 9!
System Message: Capacity of database has been enlarged to 12!
System Message: Capacity of database has been enlarged to 15!
System Message: Capacity of database has been enlarged to 18!
System Message: Capacity of database has been enlarged to 21!
System Message: Capacity of database has been enlarged to 24!
System Message: Capacity of database has been enlarged to 27!
System Message: File test.txt is successfully imported!
```
### Export Records to File
```
Please enter name of file to export: test.txt
File is Successfully Exported!
```
### Import Records from File with User-defined Attributes
```
Page: 1/1
 # Employee ID  First Name  Surname  Gender  Job Title   Salary  Form   Status  Phone No.  Date of Birth  Age  abcd  efgh
-------------------------------------------------------------------------------------------------------------------------
 1    00000001   Shun Wing     Wong       M     Intern    20000    FT   Normal  2233-3322     12-04-1998   21  ----  ----
 2    00000002     King To    Leung       M   Engineer    30000    FT   Normal  6409-9723     03-04-1988   31  ----  ----
 3    00000003  Kwong Wing       Au       M     Intern    40000    FT   Normal  2345-6789     10-10-1989   29  1234  ----
 4    00000004     Mud Cow      Lai       M   Engineer    50000    FT   Normal  9876-5432     11-11-1999   19  5678  9123
 
Q = Quit. E = Edit. N = Next. P = Previous. D = Delete. S = Sort. F = Fire. Your Choce: 
```
### Add Record with New User-Defined Attributes
```
Please enter Employee ID: 00000005
Please enter First Name: Siu Hau
Please enter Last Name: Chiu
Please enter Gender: F
Please enter Job Title: Intern
Please enter Salary: 15000
Please enter Form of Employment: PT
Please enter Job Status: Normal
Please enter Phone Number: 92348758
Please enter Date of Birth (dd-mm-yyyy): 10-10-1997
Please enter abcd: 9123
Please enter efgh: 4567
Add user defined attributes (Y/N)? Y
Number of new user defined attributes? 1
New attribute 1: ijkl
Value of ijkl: 4321

Page: 1/1
 # Employee ID  First Name  Surname  Gender  Job Title   Salary  Form   Status  Phone No.  Date of Birth  Age  abcd  efgh  ijkl
-------------------------------------------------------------------------------------------------------------------------------
 1    00000001   Shun Wing     Wong       M     Intern    20000    FT   Normal  2233-3322     12-04-1998   21  ----  ----  ----
 2    00000002     King To    Leung       M   Engineer    30000    FT   Normal  6409-9723     03-04-1988   31  ----  ----  ----
 3    00000003  Kwong Wing       Au       M     Intern    40000    FT   Normal  2345-6789     10-10-1989   29  1234  ----  ----
 4    00000004     Mud Cow      Lai       M   Engineer    50000    FT   Normal  9876-5432     11-11-1999   19  5678  9123  ----
 5    00000005     Siu Hau     Chiu       F     Intern    15000    PT   Normal  9234-8758     10-10-1997   21  9123  4567  4321

Q = Quit. E = Edit. N = Next. P = Previous. D = Delete. S = Sort. F = Fire. Your Choce: 
```
### Edit Records with User-Defined Attributes
```
Which item you want to edit: 5
Current Employee ID = 00000005, New Employee ID (Press Enter if No Change): 
Current First Name = Siu Hau, New First Name (Press Enter if No Change): 
Current Surname = Chiu, New Surname (Press Enter if No Change): 
Current Gender = F, New Gender (Press Enter if No Change): 
Current Job Title = Intern, New Job Title (Press Enter if No Change): 
Current Salary = 15000, New Salary (Press Enter if No Change): 
Current Employment Form = PT, New Employment Form (Press Enter if No Change): 
Current Status = Normal, New Status (Press Enter if No Change): 
Current Phone No. = 92348758, New Phone No. (Press Enter if No Change): 
Current Date of Birth = 10-10-1997, New Date of Birth, dd-mm-yyyy (Press Enter if No Change): 
Current abcd = 9123, New abcd. (Press Enter if No Change): aaaa
Current efgh = 4567, New efgh. (Press Enter if No Change): bbbb
Current ijkl = 4321, New ijkl. (Press Enter if No Change): cccc

Page: 1/1
 # Employee ID  First Name  Surname  Gender  Job Title   Salary  Form   Status  Phone No.  Date of Birth  Age  abcd  efgh  ijkl
-------------------------------------------------------------------------------------------------------------------------------
 1    00000001   Shun Wing     Wong       M     Intern    20000    FT   Normal  2233-3322     12-04-1998   21  ----  ----  ----
 2    00000002     King To    Leung       M   Engineer    30000    FT   Normal  6409-9723     03-04-1988   31  ----  ----  ----
 3    00000003  Kwong Wing       Au       M     Intern    40000    FT   Normal  2345-6789     10-10-1989   29  1234  ----  ----
 4    00000004     Mud Cow      Lai       M   Engineer    50000    FT   Normal  9876-5432     11-11-1999   19  5678  9123  ----
 5    00000005     Siu Hau     Chiu       F     Intern    15000    PT   Normal  9234-8758     10-10-1997   21  aaaa  bbbb  cccc
```
## Team

[![Chu Kin Ning](https://avatars1.githubusercontent.com/u/47244396?s=460&v=4)](https://github.com/u3557110) | [![Leung King To](https://avatars2.githubusercontent.com/u/49025797?s=460&v=4)](https://github.com/totoleung) 
---|---
[Chu Kin Ning](https://github.com/u3557110) | [Leung King To](https://github.com/totoleung) 

## License
