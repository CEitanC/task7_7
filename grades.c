/*
 ============================================================================
 Name        : HW7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
//#include <d3dvec.inl>
//#include "liblinked-list.so"
#include "grades.h"
#include "linked-list.h"



typedef struct _student student;
typedef struct _course course;
typedef struct grades grades;
typedef struct node node;


//user functions
int clone_student (void *element, void **output);
void destroy_student (void *element);
int clone_course (void *element, void **output);
void destroy_course (void *element);

struct grades { //Name of the data structure
    /*array of lists*/
    struct list *students_list;
    /* Store all user-function pointers here, we will need them later on! */
    //element_clone_t clone_elem;
    //element_destroy_t destroy_elem;
};

struct _student {
    char *name;
    int  id;
    float avg;
    struct list *courses;
  //  grades *grades;
};


struct _course{
	char *name;
	int grade;
	//grades *grades;
};



/* User function, clone “element” to “output”. Returns 0 on success */

int clone_student(void *element, void **output){
    if(!element || !output){
        return 1;
    }

    /*
    int error_id,error_avg;
    */
    student *new_student;
    student *out_student;

    new_student = (student*)element;
    //maybe should do casting to the list?
    out_student = (student*)output;
    //change?
    /*
    error_id = new_student->grades->clone_elem(new_student->id&,out_student->id&);
    error_avg = new_student->grades->clone_elem(new_student->avg,out_student->avg);

    if(!error_id || !error_avg) {
        return 1;
    }
     */
    out_student->id=new_student->id;
    out_student->avg=new_student->avg;


    out_student->name = (char*)malloc(sizeof(char)*(strlen(new_student->name) +1));
    if(out_student->name==NULL){return 1;}
//    out_student->courses = list_init(new_student->grades->clone_elem,new_student->grades->destroy_elem);
   // out_student->grades = (struct grades*)malloc(sizeof (struct grades*));

   /* if( !out_student->courses  ||  !out_student->name  || !out_student->grades ) {
        free(out_student->name);
        free(out_student->grades);
        free(out_student->courses);

        return 1;
    }
    */
// fixed the syntax ot strcpy
  /*  strcpy(out_student->name , new_student->name); */
    out_student->name = strcpy(out_student->name , new_student->name);

    //no need to clone by func?
//    out_student->grades = new_student->grades;

    return 0;
};

int clone_course(void *element, void **output){
    if(!element || !output) {
        return 1;
    }
    //need?
    /*
    int error_grade ;
    */
    course *new_course;
    course *out_course;
    new_course = (course*)element;
    out_course = (course*)output;

    //legal?
    /*
    error_grade = new_course->grades->clone_elem(new_course->grade,new_course->grade);
    if(!error_grade){
        return 1;
    }
	*/
    out_course->grade=out_course->grade;
   // out_course->grades = (struct grades*)malloc(sizeof (struct grades*));
    out_course->name = (char*)malloc(sizeof(char)*(strlen(new_course->name) +1));
    /*if (  !out_course->name || !out_course->grades) {
        free(out_course->grades);
        free(out_course->name);
        return 1;
    }
    */
    //maybe mistake of syntax
    if(out_course->name==NULL){return 1;}
    out_course->name = strcpy(out_course->name , new_course->name);
    //out_course->grades = new_course->grades;

    return 0;
};

void destroy_student (void *element) {
    if(!element) {
        return;
    }
    student *Student;
    Student = (student*)element;
    free(Student->name);
    // legal?
    /*
    Student->grades->destroy_elem(Student->avg);
    Student->grades->destroy_elem(Student->id);
     */
    free(Student);
};
void destroy_course (void *element) {
    if(!element) {
        return;
    }

    course *Course = (course*)element;
    free(Course->name);
    // legal?
    /*
    Course->grades->destroy_elem(Course->grade);
    */

    free(Course);
};



//int element_clone(void *element, void **output) {
//    grades *tmp_grade = (grades *) element;
//    node *out = (node *) output;
//    grades *new_grade = (grades *) malloc(sizeof(grades));
//    if (new_grade == NULL) {
//        return 1;
//    }
//    new_grade->grade = tmp_grade->grade;
//    new_grade->next = tmp_grade->next;
//    char *new_course = (char *) malloc(sizeof(char) * (strlen(tmp_grade->course) + 1));
//    if (new_course == NULL) {
//        free(new_grade);
//        return 1;
//    }
//
//    strcpy(new_course, tmp_grade->course);
//    new_grade->course = new_course;
//    *output = new_grade;
//    return 0;
//}
/*
	out->name =
	out->grade = (grades*)malloc(sizeof(grades));
	out->next =  (node*)malloc(sizeof(node));

	strcpy(arg->name,out->name);
	out->id = arg->id;
	out->next = arg->next;


	strcpy(arg->grade-course,out->course);
	out->grade = arg->grade;

	out->
*/
//};
//
//struct list{
//	node* head,tail;
//	element_clone_t elem_clone;
//	element_destroy_t list_destroy;
//};




/**
 * @brief Initializes the "grades" data-structure.
 * @returns A pointer to the data-structure, of NULL in case of an error
 */


struct grades* grades_init(){
	grades *Grades;
//    struct list **students;
  //  int error=0;

    Grades = (struct grades*)malloc(sizeof (struct grades));
   // students = (struct list**)malloc(sizeof (struct list*));

    if(Grades==NULL){
        return NULL;
    }

    Grades->students_list=list_init(clone_student, destroy_student );
    //students = list_init(clone_student, destroy_student );
    if(Grades->students_list==NULL){
        free(Grades);
    }


//need?
    /*
    Grades->clone_elem = *clone_element;
    Grades->destroy_elem = *destroy_element;
    */
   // Grades->students_list = students;
	return Grades;
};

/**
 * @brief Destroys "grades", de-allocate all memory!
 */
void grades_destroy(struct grades *grades){
        if(!grades){
            return;
        }
        //maybe syntax wrong
        /*
        node *it = list_begin(grades->students_list);
        */
        node *it = list_begin(grades->students_list);
        student *s;
        while (!it){
            s = (student*)list_get(it);
            list_destroy(s->courses);
        }
        list_destroy(grades->students_list);
        free(grades);
};

/**
 * @brief Adds a student with "name" and "id" to "grades"
 * @returns 0 on success
 * @note Failes if "grades" is invalid, or a student with
 * the same "id" already exists in "grades"
 */
int grades_add_student(struct grades *grades, const char *name, int id){
    //Check Arguments
    if(!grades || !name || !id){
        return 1;
    }
    node *it = list_begin(grades->students_list);
    if( !it ){
        return 1;
    }
    student* s;
    while(it != NULL){
        s = (student*)list_get(it);
            if(s->id == id) {
                return 1;
            }

        it = list_next(it);
    }

    student* new_student=(student*)malloc(sizeof(student));
    if(new_student==NULL){return 1;}
    char *new_name = (char*)malloc(strlen(name)+1);
    if(new_name==NULL){
    	free(new_student);
    	return 1;
    }
    new_name = strcpy(new_name, name);
    new_student->name=new_name;
    new_student->id=id;
    new_student->avg= 0;
    new_student->courses=list_init(clone_course,destroy_course);
   // student.grades = list_init(clone_course,destroy_course);

    return list_push_back(grades->students_list , &new_student );
};




/**
 * @brief Adds a course with "name" and "grade" to the student with "id"
 * @return 0 on success
 * @note Failes if "grades" is invalid, if a student with "id" does not exist
 * in "grades", if the student already has a course with "name", or if "grade"
 * is not between 0 to 100.
 */
int grades_add_grade(struct grades *grades,
                     const char *name,
                     int id,
                     int grade){
    if( !grades || grade < 0 || grade > 100 ) {
        return 1;
    }
    node *it = list_begin(grades->students_list);
    student *s;
    while( !it ) {
             s = (student*)list_get(it);
            if(s->id == id) {
                break;
            }

        it = list_next(it);
    }
    if(!it){
        return 1;
    }

    /**student exist in the data structre**/
    it = list_begin(s->courses);
    course *c;
    while( !it ){
        c = (course*)list_get(it);
        if(strcmp(c->name,name)){
            return 1;
        }
        it = list_next(it);
    }

    /**The student don't have grade in the course yet**/
    /**avg update**/
    s->avg = (s->avg + grade )/(list_size(s->courses) + 1);
    // insert new cpurse
    course *new_course = (course*)malloc(sizeof(student));
    if(new_course==NULL){
    	return 1;
    }

    char* new_name= (char*)malloc(strlen(name)+1);
    if(new_name==NULL){return 1;}

    new_name = strcpy(new_name,name);
    new_course->name=new_name;
  //  new_course->grades = grades;
    new_course->grade = grade;

    return list_push_back(s->courses , &new_course);
};

/**
 * @brief Calcs the average of the student with "id" in "grades".
 * @param[out] out This method sets the variable pointed by "out" to the
 * student's name. Needs to allocate memory. The user is responsible for
 * freeing the memory.
 * @returns The average, or -1 on error
 * @note Fails if "grades" is invalid, or if a student with "id" does not exist
 * in "grades".
 * @note If the student has no courses, the average is 0.
 * @note On error, sets "out" to NULL.
 */
float grades_calc_avg(struct grades *grades, int id, char **out){
    if(!grades){
        return -1;
    }

    node *it = list_begin(grades->students_list);
    student *s;
    while( !it ){
        s = list_get(it);
        if(s->id == id){
            break;
        }
        it = list_next(it);
    }
    if( !it ){
        return -1; /**student was not found**/
    }
/*
    size_t sz;
    sz = snprintf(NULL, 0,
                  "The average of %s (id: %d) is %f", s->name, s->id, s->avg);
    out = (char*)malloc(sz +1);
    */
    out= (char**)malloc(strlen(s->name)+1);
    if(out==NULL){return 0;}
   // snprintf(out, sz+1,"The average of %s (id: %d) is %f", s->name, s->id, s->avg);
    *out= strcpy((char*)out,s->name);
    return s->avg;

};

/**
 * @brief Prints the courses of the student with "id" in the following format:
 * STUDENT-NAME STUDENT-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * @returns 0 on success
 * @note Fails if "grades" is invalid, or if a student with "id" does not exist
 * in "grades".
 * @note The courses should be printed according to the order
 * in which they were inserted into "grades"
 */
int grades_print_student(struct grades *grades, int id){
    if(!grades) {
        return 1;
    }
    node *it = list_begin(grades->students_list);
    student *s;
    while (!it){
        s = (student*)list_get(it);
        if(s->id == id){
            break;
        }
        it = list_next(it);
    }
    if(!it){
        return 1;
    }
    it = list_begin(s->courses);
    course *c;
    printf("%s %d: ",s->name,s->id);
    do {
        c = (course*)list_get(it);
        printf("%s %d,",c->name,c->grade);
        it = list_next(it);
    }while (!it);

    printf("%s %d\n",c->name,c->grade);
    return 0;

};

/**
 * @brief Prints all students in "grade", in the following format:
 * STUDENT-1-NAME STUDENT-1-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * STUDENT-2-NAME STUDENT-2-ID: COURSE-1-NAME COURSE-1-GRADE, [...]
 * @returns 0 on success
 * @note Fails if "grades" is invalid
 * @note The students should be printed according to the order
 * in which they were inserted into "grades"
 * @note The courses should be printed according to the order
 * in which they were inserted into "grades"
 */
int grades_print_all(struct grades *grades){
    if(!grades){
        return 1;
    }
    node *it = list_begin(grades->students_list);
    student *s;
    while (!it){
        s = (student*)list_get(it);
        grades_print_student( grades , s->id );
        it = list_next(it);
    }
    return 0;
};

