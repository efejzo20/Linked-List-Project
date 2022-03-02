# Linked-List-Project
Handling student data with Linked List

## Project details

C program that takes 4 parameters from command line: input fileName, output
fileName, department and status (0/1), where:

- Input fileName: is the name of the file containing student’s information.
- output filename: is the name of the file to write the required information.
- department: studding department.
- status: 0=> students with CGPA <2.8 and 1=> student with CGPA >= 2.8.

The program read all students information from the input file, and according to the
given parameters (dep and status) it prints to the screen and write students information
to the output file.

### Input Specification:
In the first line there is the number of students (n), and the following n lines contain name,
surname, department, 1st year GPA, 2nd year GPA and 3rd year GPA for each student. Where:
- Student name is at most 25 char long
- Student surname is at most 25 char long
- Student Dep is at most 5 char long
- 1st year GPA is a floating point number
- 2nd year GPA is a floating point number
- 3rd year GPA is a floating point number

### Output Specification:
Write and print the name, surname, department and GPA of the required students.
