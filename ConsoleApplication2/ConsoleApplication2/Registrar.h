#include <iostream>
#include<vector>
#include<string>


using namespace std;
class Student;
class Course;
class registrar;




class Course {

private:
    string coursename;
    vector<Student*>students;
public:
    Course(string name) {
        coursename = name;
    }
    ~Course()
    {
        students.clear();
    }
    string getname()
    {
        return coursename;
    }
    void addstudent(Student* s) {
        students.push_back(s);
    }
    void removeStudentsfromCorse() {
        students.clear();
    }
    friend ostream& operator <<(ostream& out, const Course& o)
    {
        out << o.coursename << " ";
        // out << " " << o.getname() << ":" << "/t";
        for (size_t i = 0; i < o.students.size(); i++) {

            //note
             // out << o.students[i]->getname() << "/t";
        }
        //out << "/n";
        return out;
    }

};

class Student
{

private:
    string studentname;
    vector<Course*>courses;
public:
    Student(string name1) {
        studentname = name1;
    }

    ~Student()
    {
        courses.clear();
    }
    string getname()
    {
        return studentname;
    }
    bool addcourse(Course* c)
    {
        int scan = -1;
        for (int i = 0; i < courses.size(); i++) {

            if (courses[i]->getname() == c->getname())
            {
                scan = 1; break;
            }
        }
        if (scan == 1) {
            cout << "the student is really in the course";
            return false;
        }
        else {
            courses.push_back(c);
            return true;
        }
    }
    void removedfromcourse(Course* c)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (c->getname() ==courses[i]->getname())
            {
                courses.erase(i);
            }
        }

    }

    friend ostream& operator  <<(ostream& out, Student& co);

    {
        out << co.studentname << endl;
        for (int i = 0; i < co.courses.size(); i++)
        {
            out << co.courses[i]->getname();
        }
        return out;
    }


};

class registrar {
private:
    vector<Course*>courses;
    vector<Student*>students;
    int find_student(string studentname)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i]->getname() == studentname) {
                return i;
            }
        }
        return -1;
    }

    int find_course(string coursename) {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i]->getname() == coursename) {
                return i;
            }
        }
        return -1;
    }


public:
    registrar()
    {

    }
    bool addcourse(string coursename)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i]->getname() == coursename) {
                return false;
            }
        }
        courses.push_back(new Course(coursename));
        return true;
    }

    bool addstudent(string studentname)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i]->getstudentname() == studentname) {
                return false;
            }
        }
        students.push_back(new student(studentname));
        return true;
    }

    bool enrollstudentincourse(string studentname, string coursename)
    {
        int i, j;
        i = find_student(studentname);
        j = find_course(coursename);
        if (i <= 0 && j <= 0) {
            students[i]->addcourse(courses[j]);
            courses[j]->addstudent(students[i]);
            return true;
        }
        else {
            return false;

        }

    }
    bool cancelcourse(const string name)
    {
        int i = findcourse(name);
        if (i >= 0) {
            course.erase(courses.begin() + i);
        }
        for (int j = 0; j < students.size(); j++)
        {
            if (i >= 0) { courses.erase(courses.begin() + 1); }
            if (strcmp(name, courses[j]->getname()) == 0) {
                courses.erase(courses.begin() + j);
            }
        }
    }

    void clear()
    {
        students.clear();
        courses.clear();
    }
    ostream& operator <<(ostream& out, register& ob) {
        for (int i = 0; i < ob.courses.shze(); i++)
        {
            out << ob.coursrs[i] << endl;
            for (int a = 0; a < ob.student.size(); a++)
            {
                out << ob.student[a] << endl;
            }
            return out;
        }
    }


};

int main()
{


}
