#include <iostream>
#include <vector>
#include <string>



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
            if (c->getname() == courses[i]->getname())
            {
                courses.erase(courses.begin() + i);
            }
        }

    }

    friend ostream& operator  <<(ostream& out, Student& co)

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
            if (students[i]->getname() == studentname) {
                return false;
            }
        }
        students.push_back(new Student(studentname));
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
        int i = find_course(name);
        if (i >= 0) {
            courses.erase(courses.begin() + i);
            return false;
        }
        for (int j = 0; j < students.size(); j++)
        {
            if (i >= 0) { courses.erase(courses.begin() + 1); }
            if (name == courses[j]->getname()) {
                courses.erase(courses.begin() + j);
            }


        }
        return true;
    }

    void clear()
    {
        students.clear();
        courses.clear();
    }
    friend  ostream& operator<<(ostream& out, const registrar& ob) {
        for (int i = 0; i < ob.courses.size(); i++)
        {
            out << *ob.courses[i] << endl;
        }
            for (int a = 0; a < ob.students.size(); a++)
            {
                out << *ob.students[a] << endl;
            }
            return out;
        }
    




};

int main()
{

    registrar registrar;
    cout << registrar << endl;
    cout << "AddCourse DS10636211\n";
    registrar.addcourse("DS10636211");
    cout << registrar << endl;
    cout << "AddStudent Ali_Ahmad\n";
    registrar.addstudent("Ali_Ahmad");
    cout << registrar << endl;
    cout << "AddCourse Java10636212\n";
    registrar.addcourse("Java10636212");
    cout << registrar << endl;
    cout << "EnrollStudentInCourse Ali_Ahmad DS10636211\n";
    registrar.enrollstudentincourse("Ali_Ahmad", "DS10636211");
    cout << "EnrollStudentInCourse Ali_Ahmad Java10636212\n";
    registrar.enrollstudentincourse("Ali_Ahmad", "Java10636212");
    cout << registrar << endl;
    cout << "EnrollStudentInCourse Haya_Samaana DS10636211\n";
    cout << "Should fail since Haya_Samaana is not a student.\n";
    registrar.enrollstudentincourse("Haya_Samaana", "DS10636211");
    cout << registrar << endl;
    cout << "CancelCourse DS10636211\n";
    registrar.cancelcourse("DS10636211");
    cout << registrar << endl;
    cout << "Clear system to start new semester\n";
    registrar.clear();
    cout << registrar << endl;
    return 0;
}

/*
using namespace std;
class Student;
class Course;
class Registrar;
class Course {
private:
	string courseName;
	vector<Student*> students;
public:
	Course(string name) {
		courseName = name;
	}
	~Course() {
		students.clear();
	}
	string getName() {
		return courseName;
	}
	void addStudent(Student* s) {
		students.push_back(s);
	}
	void removeStudentsFromCourse() {
		students.clear();
	}
	friend ostream& operator<<(ostream& os, const Course& c) {
		os << c.courseName << " ";
		for (int i = 0; i < c.students.size(); i++) {
			//os << c.students[i]->getName() << " ";
		}
		return os;
	}
};


class Student {
private:
	string studentName;
	vector<Course*> courses;
public:

	Student(string name) {
		studentName = name;
	}
	~Student() {
		courses.clear();
	}
	string getName() {
		return studentName;
	}
	bool addCourse(Course* c) {
		for (int i = 0; i < courses.size(); i++) {
			if (courses[i]->getName() == c->getName()) {
				return false;
			}
		}
		courses.push_back(c);
		return true;
	}
	void removedFromCourse(Course* c) {
		for (int i = 0; i < courses.size(); i++) {
			if (courses[i]->getName() == c->getName()) {
				courses.erase(courses.begin() + i);
			}
		}
	}
	friend ostream& operator<<(ostream& os, const Student& s) {
		os << s.studentName << " ";
		for (int i = 0; i < s.courses.size(); i++) {
			os << s.courses[i]->getName() << " ";
		}
		return os;
	}
};
class Registrar {
private:
	vector<Course*> courses;
	vector<Student*> students;
	int findStudent(string studentName) {
		for (int i = 0; i < students.size(); i++) {
			if (students[i]->getName() == studentName) {
				return i;
			}
		}
		return -1;
	}
	int findCourse(string courseName) {
		for (int i = 0; i < courses.size(); i++) {
			if (courses[i]->getName() == courseName) {
				return i;
			}
		}
		return -1;
	}
public:
	Registrar() {}
	bool addCourse(string courseName) {
		for (int i = 0; i < courses.size(); i++) {
			if (courses[i]->getName() == courseName) {
				return false;
			}
		}
		courses.push_back(new Course(courseName));
		return true;
	}
	bool addStudent(string studentName) {
		for (int i = 0; i < students.size(); i++) {
			if (students[i]->getName() == studentName) {
				return false;
			}
		}
		students.push_back(new Student(studentName));
		return true;
	}
	bool enrollStudentInCourse(string studentName, string courseName) {
		int studentIndex = findStudent(studentName);
		int courseIndex = findCourse(courseName);
		if (studentIndex == -1 || courseIndex == -1) {
			return false;
		}
		students[studentIndex]->addCourse(courses[courseIndex]);
		courses[courseIndex]->addStudent(students[studentIndex]);
		return true;
	}
	bool cancelCourse(string courseName) {
		int courseIndex = findCourse(courseName);
		if (courseIndex == -1) {
			return false;
		}
		courses[courseIndex]->removeStudentsFromCourse();
		courses.erase(courses.begin() + courseIndex);
		return true;
	}
	void clear() {
		courses.clear();
		students.clear();
	}
	friend ostream& operator<<(ostream& os, const Registrar& r) {
		for (int i = 0; i < r.courses.size(); i++) {
			os << *r.courses[i] << endl;
		}
		for (int i = 0; i < r.students.size(); i++) {
			os << *r.students[i] << endl;
		}
		return os;
	}
};
int main() {
	Registrar registrar;
	cout << registrar << endl;
	cout << "AddCourse DS10636211\n";
	registrar.addCourse("DS10636211");
	cout << registrar << endl;
	cout << "AddStudent Ali_Ahmad\n";
	registrar.addStudent("Ali_Ahmad");
	cout << registrar << endl;
	cout << "AddCourse Java10636212\n";
	registrar.addCourse("Java10636212");
	cout << registrar << endl;
	cout << "EnrollStudentInCourse Ali_Ahmad DS10636211\n";
	registrar.enrollStudentInCourse("Ali_Ahmad", "DS10636211");
	cout << "EnrollStudentInCourse Ali_Ahmad Java10636212\n";
	registrar.enrollStudentInCourse("Ali_Ahmad", "Java10636212");
	cout << registrar << endl;
	cout << "EnrollStudentInCourse Haya_Samaana DS10636211\n";
	cout << "Should fail since Haya_Samaana is not a student.\n";
	registrar.enrollStudentInCourse("Haya_Samaana", "DS10636211");
	cout << registrar << endl;
	cout << "CancelCourse DS10636211\n";
	registrar.cancelCourse("DS10636211");
	cout << registrar << endl;
	cout << "Clear system to start new semester\n";
	registrar.clear();
	cout << registrar << endl;
	return 0;
}*/