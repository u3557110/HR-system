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

## Team

[![Chu Kin Ning](https://avatars1.githubusercontent.com/u/47244396?s=460&v=4)](https://github.com/u3557110) | [![Leung King To](https://avatars2.githubusercontent.com/u/49025797?s=460&v=4)](https://github.com/totoleung) 
---|---
[Chu Kin Ning](https://github.com/u3557110) | [Leung King To](https://github.com/totoleung) 

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
### Show Record
```
Page: 1/3
 # Employee ID  First Name  Surname  Gender  Job Title   Salary  Form   Status  Phone No.  Date of Birth  Age
-------------------------------------------------------------------------------------------------------------
 1    00000001   Shun Wing     Wong       M        CEO   100000    FT   Normal  2233-3322     12-04-1978   41
 2    00000002     King To    Leung       M        CTO    90000    FT   Normal  6409-9723     03-04-1988   31
 3    00000003   Hing Wong     Chan       M        CFO    90000    FT   Normal  6409-9723     03-04-1982   37
 4    00000004     Sze Tat     Chau       M   Director    80000    FT   Normal  6409-9723     03-04-1988   31
 5    00000005    Bean Y C       Ho       M   Director    80000    FT   Normal  6409-9723     03-04-1984   35
 6    00000006       Doris       Lo       F        SVP    70000    FT   Normal  6409-9723     03-04-1988   31
 7    00000007        Hyde     Hang       M        SVP    70000    FT   Normal  6409-9723     03-04-1985   34
 8    00000008     Tai Man     Chau       M         VP    60000    FT   Normal  6409-9723     03-04-1988   31
 9    00000009    Siu Ming     Chan       M    Manager    50000    FT   Normal  6409-9723     03-04-1978   41
10    00000010     Sui Kit       Au       M    Manager    50000    FT   Normal  6409-9723     03-04-1968   51
```
## License
