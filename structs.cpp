#include <iostream>

/*
 * Here, we're defining a new struct to represent a student.  The struct has
 * fields to store the student's name, ther student's ID number, and the
 * student's GPA.
 */
struct student {
  std::string name;
  int id;
  float gpa;
};


int main(int argc, char** argv) {

  /*
   * Here, we're declaring a statically allocated struct (a struct allocated
   * on the call stack) and at the same time initializing it using designated
   * initialization, where we use the dot-notation below to initialize the
   * values of specific fields in the struct (here, the student's name and ID).
   * Any fields we don't initialize in our designated initializer will be
   * given default values (e.g. here, gpa will be 0).
   */
  struct student s1 = { .name = "Luke Skywalker", .id = 933123456 };

  /*
   * Here, we access the values of the fields of s1 to print them out.
   * Because s1 is statically allocated, we use the dot notation below to
   * access its fields' values.
   */
  std::cout << "ID for " << s1.name << ": " << s1.id << std::endl;

  /*
   * We can use the same dot notation to set the value of a field in a
   * statically-allocated struct, like below, where we set s1's GPA.
   */
  s1.gpa = 3.9;
  std::cout << "GPA for " << s1.name << ": " << s1.gpa << std::endl;

  /*
   * Here, we use the new operator to dynamically allocate a second student
   * struct (i.e. to allocate it on the heap).
   */
  struct student* s2 = new struct student;

  /*
   * Here, we set and access some of the fields of our dynamically-allocated
   * student struct.  Because we have a pointer to a student struct here, we
   * need to dereference the pointer (i.e. get the value--the student struct--it
   * points to) before we can access its fields.  We use the arrow notation
   * below, which does two things: dereferences a pointer to a struct and
   * then accesses one of its fields.  In other words, using s2->name is the
   * same as using (*s2).name.
   *
   * We set the ID number for s2 based on user input, to show how we can use
   * a struct in conjunction with std::cin.  The same would work if we were
   * using an ifstream to input from a file instead of using std::cin.
   */
  s2->name = "Darth Vader";
  std::cout << "Please input the ID number for " << s2->name << std::endl;
  std::cin >> s2->id;
  std::cout << "ID for " << s2->name << ": " << s2->id << std::endl;

  /*
   * As always, we need to use the delete operator to free the memory we
   * allocated with the new operator.
   */
  delete s2;

}
