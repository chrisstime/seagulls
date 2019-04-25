/**********************************************************************
48430 Embedded C - Assignment 2
Name:                   Melisa Sachi
Student ID:             11984566
Date of submission:     22/05/16
A brief statement on what you could achieve (less than 50 words):
- All the functions required (add student, delete last student,
  display student list, save the student list to the database, read
  the student list from the database, exit the program)
- Handle inexperienced users
- Handle hostile users
 
A brief statement on what you could NOT achieve (less than 50 words):
---

**********************************************************************/

/**********************************************************************
List of header files - you may use any standard C libraries.
List preprocessing directives - you may define your own.
List structs - you may define struct date and struct student only.
**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Maximum number of students in the class */
#define MAX_CLASS_SIZE 5
/* Maximum length of the string - student name. Note that all strings
in C are NULL terminated i.e. '\0' at the end of the string. Hence the
length of the actual name can be 10 characters at most*/
#define MAX_NAME_SIZE 11 
/* Static file name of the text file where student list is stored */
#define DB_FILE_NAME "database"


/* struct date - contains
	day - unsigned integer between 1 and 31 (inclusive)
	month - unsigned integer between 1 and 12
	year - unsigned integer between 1800 and 2016
Note: do not worry about some months not having dates 29-31. That means
30-02-1900 is a real date, although the month of Feb does not have a
day30.
*/
struct date{
    int day,
        month,
        year;
};

typedef struct date date_t;

/* struct student - contains
        name - array of MAX_NAME_SIZE chars (string)
        birthday - a struct type 'date' defined above
        gpa - a float between 0.0 and 4.0
*/
struct student{
    char    name[MAX_NAME_SIZE];
    struct  date birthday;
    float   gpa;
};

typedef struct student student_t;

/**********************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
**********************************************************************/
void printmenu(void);

void addstudent(student_t* const);
void readnameinput(char*);
int readintinput(const char*, const char*, int, int);
float readfloatinput(const char*, const char*, float, float);

void deletestudent(int* const);
void displaystudents(const student_t*, int);
void savestudents(const student_t*, int);
void readstudents(student_t*, int* const);

int unreadinput(void);
void clearstdin(void);

/**********************************************************************
Main
**********************************************************************/
int main(void)
{   
    char inputbuffer[30];
    int menuchoice = 0;
    student_t studentlist[MAX_CLASS_SIZE];
    int classsize = 0;
    
    /* Repeat until the user exits the program */
    while(menuchoice != 6)
    {          
        printmenu();
        printf("Enter your choice>");
        
        /* Check if scanf is able to read all the input (ie. if it's an integer) */
        if(scanf("%[0-9]s", inputbuffer) && unreadinput() == 0)
        {
            menuchoice = atoi(inputbuffer);
            switch (menuchoice)
            {
                case 1:
                    /* If the class is already full, you can't add a new student */
                    if (classsize == MAX_CLASS_SIZE)
                    {
                        printf("Class is full\n");
                    }
                    else
                    {
                        /* Increase the class size and add the new student */
                        classsize++;
                        addstudent(&studentlist[classsize - 1]);
                    }
                    break;

                case 2:
                    /* If the class is empty, you can't delete a student */
                    if (classsize == 0)
                    {
                        printf("Class is empty\n");
                    }
                    else
                    {
                        deletestudent(&classsize);
                    }
                    break;

                case 3:
                    /* Don't display if there's no one in the class */
                    if (classsize == 0)
                    {
                        printf("Class is empty\n");
                    }
                    else
                    {
                        displaystudents(studentlist, classsize);
                    }
                    break;

                case 4:
                    savestudents(studentlist, classsize);
                    break;

                case 5:
                    readstudents(studentlist, &classsize);
                    break;

                case 6:
                    /* Do nothing */
                    break;

                default:
                    /* The user has entered a value outside of the range allowed */
                    printf("Invalid choice.\n");
                    break;
            }
        }
        else
        {
            /* Otherwise, the input is not an integer and scanf cannot read all of it */
            printf("Invalid choice.\n");
        }
        
        /* Clear the input feed */
        clearstdin();
    }
    
    return 0;
}

/**********************************************************************
Print 2 empty lines followed by the choices menu.
**********************************************************************/
void printmenu()
{
    printf("\n\n"
    	"1. add student\n"
    	"2. delete last student\n"
    	"3. display student list\n"
    	"4. save the student list to the database\n"
    	"5. read the student list from the database\n"
    	"6. exit the program\n");
}


/**********************************************************************
Adds a new student to the studentlist, prompting for and reading
their input.

Inputs:
    student_t* const student_p - const pointer to the student_t object
                                 to store the input information in
**********************************************************************/
void addstudent(student_t* const student_p)
{   
    /* Read the student's name, birthday and GPA */
    readnameinput(student_p->name);
    student_p->birthday.day = readintinput("Enter birthday: day>", "Invalid day. ", 1, 31);
    student_p->birthday.month = readintinput("Enter birthday: month>", "Invalid month. ", 1, 12);
    student_p->birthday.year = readintinput("Enter birthday: year>", "Invalid year. ", 1800, 2016);
    student_p->gpa = readfloatinput("Enter GPA>", "Invalid GPA. ", 0.0, 4.0);
}

/**********************************************************************
Prompts the user for the student's name and reads in their input.

Input:
    char namedestination[] - destination for storing the name input
**********************************************************************/
void readnameinput(char namedestination[])
{
    /* Clear the input buffer before reading in values*/
    clearstdin();
    
    /* Prompt for and read the student's name, reading input until the
       newline character to allow for spaces                           */
    printf("%s", "Enter name>");
    scanf("%[^\n]", namedestination);
    
    /* Check if the string read is longer than allowed */
    if(strlen(namedestination) >= MAX_NAME_SIZE)
    {
        /* If so, end the string at the maximum length */
        namedestination[MAX_NAME_SIZE - 1] = '\0';
    }
}

/**********************************************************************
Prompts the user for an integer using a specified prompt and reads in
their input. Repeats if the input is invalid.

Input:
    const char prompt[] - question/prompt to print to the user
    const char errormsg[] - error message to display if the user
                            enters an invalid value
    int minval - the minimum value allowed for the user input
    int maxval - the maximum value allowed for the user input

Output:
    int - user's int input
**********************************************************************/
int readintinput(const char prompt[], const char errormsg[], int minval, int maxval)
{
    /* Clear the input buffer before reading in values*/
    clearstdin();
    
    /* Holds the input read */
    char inputbuffer[30];
    int input = 0;
    
    /* Loop until it returns a value */
    while(1 == 1)
    {
        printf("%s", prompt);
        
        /* Check if scanf is able to read all of the input (ie. if it's an integer).
           Allows scanf to only take in chars from '0' to '9'                        */   
        if(scanf("%[0-9]s", inputbuffer) > 0 && unreadinput() == 0)
        {
            /* Convert input into an int */
            input = atoi(inputbuffer);
            
            if (input >= minval && input <= maxval)
            {
                /* Only return the input if it's within the specified range */
                return input;      
            }
        }
        
        /* If scanf can't read the input, or if the input is not in the 
           specified range, print an error message and clear the input feed */
        printf("%s", errormsg);
        clearstdin();
    }
}

/**********************************************************************
Prompts the user for a float using a specified prompt and reads in
their input. Repeats if the input is invalid.

Input:
    const char prompt[] - question/prompt to print to the user
    const char errormsg[] - error message to display if the user
                            enters an invalid value
    float minval - the minimum value allowed for the user input
    float maxval - the maximum value allowed for the user input

Output:
    float - user's float input
**********************************************************************/
float readfloatinput(const char prompt[], const char errormsg[], float minval, float maxval)
{
    /* Clear the input buffer before reading in values*/
    clearstdin();
    
    /* Holds the input read */
    char inputbuffer[30];
    float input = 0;
    
    /* Loop until it returns a value */
    while(1 == 1)
    {
        printf("%s", prompt);
        
        /* Check if scanf is able to read the input (ie. if it's a float).
           Allows scanf to only take in '.' or chars from '0' to '9'       */
        if(scanf("%[0-9.]s", inputbuffer) > 0 && unreadinput() == 0)
        {
            /* Convert input into a float */
            input = atof(inputbuffer);
            
            if (input >= minval && input <= maxval)
            {
                /* Only return the input if it's within the specified range */
                return input;      
            }
        }
        
        /* If scanf can't read the input, or if the input is not in the 
           specified range, print an error message and clear the input feed */
        printf("%s", errormsg);
        clearstdin();
    }
}


/**********************************************************************
Removes the last student from the studentlist.

Inputs:
    int* const classsize_p - const pointer to the current class size
**********************************************************************/
void deletestudent(int* const classsize_p)
{
    /* Decrements the value of classsize */
    (*classsize_p)--;
}

/**********************************************************************
Displays the list of students in the following format as shown in
the specification:
    Name       Birthday   GPA
    ---------- ---------- ------
    bee        10-01-1800 4.0000

Inputs:
    const student_t students[] - current array of students in the class
    int classsize - current class size
**********************************************************************/
void displaystudents(const student_t students[], int classsize)
{
    printf("Name\t   Birthday   GPA\n");
    printf("---------- ---------- ------\n");
            
    /* Loops through each student in the class and prints their information */
    int i;
    for(i = 0; i < classsize; i++)
    {
        /* Determines how many spaces should be printed after the student's name */
        int namepadlen = 10 - strlen(students[i].name);

        /* Prints the student's name and the appropriate padding */
        printf("%s", students[i].name);
        printf("%.*s ", namepadlen, "          ");

        /* Prints the student's birthday in the format 'dd-mm-yyyy'
           Pads days and months with 0's as required                */
        printf("%02d-%02d-%d ", students[i].birthday.day,
                students[i].birthday.month, students[i].birthday.year);

        /* Prints the student's GPA to four decimal places */
        printf("%.4f\n", students[i].gpa);
    }
}

/**********************************************************************
Save the studentlist in the hard disk as a text file named database.
Overwrites if the database file already exists.

Inputs:
    const student_t students[] - current array of students in the class
    int classsize - current class size
**********************************************************************/
void savestudents(const student_t studentlist[], int classsize)
{
    /* Open or create the file to write to, overwriting any previous data */
    FILE* file_p;
    file_p = fopen(DB_FILE_NAME, "w");
    
    /* If the file cannot be opened, alert the user */
    if(!file_p)
    {
        printf("Write error");
    }
    else
    {
        /* Loop through each student in the class */
        int i;
        for(i = 0; i < classsize; i++)
        {
            /* Write the student's information to the file with tabs
               between each piece of data                            */
            fprintf(file_p, "%s\t%d\t%d\t%d\t%f\t",
                        studentlist[i].name,
                        studentlist[i].birthday.day,
                        studentlist[i].birthday.month,
                        studentlist[i].birthday.year,
                        studentlist[i].gpa);
        }
        
        /* Close the file */
        fclose(file_p);
    }
}

/**********************************************************************
Reads the database file and puts the data into studentlist.
Overwrites the studentlist array in memory.
Assumes the data in database is fully compliant with the datatype and
range requirements.
Updates the number of students in the class.

Input:
    student_t students[] - current array of students in the class
    int* const classsize_p - const pointer to the current class size
**********************************************************************/
void readstudents(student_t studentlist[], int* const classsize_p)
{
    /* Open the file to read from */
    FILE* file_p;
    file_p = fopen(DB_FILE_NAME, "r");
    
    /* If the file cannot be opened, alert the user */
    if(!file_p)
    {
        printf("Read error\n");
    }
    else
    {   
        /* Index counter used to iterate through the studentlist */
        int i = 0;
        
        /* Read until the end of file */
        while(!feof(file_p))
        {
            /* Read from the file and store data in studentlist */
            fscanf(file_p, "%[^\t]%d\t%d\t%d\t%f\t",
                    studentlist[i].name,
                    &(studentlist[i].birthday.day),
                    &(studentlist[i].birthday.month),
                    &(studentlist[i].birthday.year),
                    &(studentlist[i].gpa));
            
            i++;
        }
        
        /* Number of iterations is the number of students */
        *classsize_p = i;
        
        /* Close the file */
        fclose(file_p);
    }
}


/**********************************************************************
Checks if there is any unread input in stdin.

Output:
    int - flag indicating if there was any unread input found.
        - returns 0 if nothing was found and 1 otherwise.
**********************************************************************/
int unreadinput()
{
    /* Check if there is anything unread in the input buffer
       (eg. if scanf was unable to read any of the input     */
    if (getchar() == '\n')
    {
        /* If so, replace the newline character removed on the previous line */
        ungetc('\n', stdin);

        return 0;
    }
    else
    {
        /* Otherwise, something unread was found in the inputbuffer */
        return 1;
    }
}

/**********************************************************************
Clears all values in stdin.
**********************************************************************/
void clearstdin()
{
    /* Get input from stdin until it has cleared all current input
       (ie. until it reaches the newline character '\n')            */
    while(getchar() != '\n');
}

