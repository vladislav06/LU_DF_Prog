/*
 *  PiPLa0603. Sastādīt C++ programmu, kas izveido failu ar ziņām par studiju kursiem.
 *  Ziņas par studiju kursiem jāglabā binārā komponenšu failā (ieraksti ar vienādu garumu).
 *  Komponentes saturs: nosaukums, kursa daļa (A, B, C), kredītpunktu skaits, kursa kods (1-100).
 *  Informācija par studiju kursiem faila veidošanai jāņem no standartieejas plūsmas faila cin.
 *  Komponentes failā jāraksta ar tiešo pieeju, izmantojot kursa kodu kā komponentes numuru.
 */
#include <iostream>
#include <string.h>
#include <list>
#include <fstream>


using namespace std;

class Course {
private:
    char name[51] = "qewfaewf";
    char part = 'A';//A,B,C
    int creditPointCount = 0;
    int code = 1; // 1-100
public:
    const char *getName() const {
        return name;
    }

    void setName(string _name) {
        if (_name.length() > 50)
            return;
        strcpy(this->name, _name.c_str());
    }

    char getPart() const {
        return part;
    }

    void setPart(char _part) {
        if (_part != 'A' && _part != 'B' && _part != 'C')
            return;
        this->part = _part;
    }

    int getCreditpointsCount() const {
        return creditPointCount;
    }

    void setCreditPointCount(int _creditpointsCount) {
        this->creditPointCount = _creditpointsCount;
    }

    int getCode() const {
        return code;
    }

    void setCode(int _code) {
        if (_code > 100)
            return;
        this->code = _code;
    }

    /// returns size of this object
    int getSerializedDataSize() {
        return sizeof *this;
    }

    /// writes its own contents to data array
    /// data array must be sufficient size!
    void serialize(char *data) {
        memcpy(data, this, getSerializedDataSize());
    }

};


void getCourses(list<Course> &courses) {
    while (true) {
        Course course;

        cout << "Ievadiet kursa nosaukumu(maks. 50 burti):";
        string name;
        cin >> name;
        course.setName(name);


        cout << "Ievadiet kursa daļu(A vai B vai C):";
        char part;
        cin >> part;
        course.setPart(part);

        cout << "Ievadiet kursa kreditpunku skaitu:";
        int creditPointCount;
        cin >> creditPointCount;
        course.setCreditPointCount(creditPointCount);


        cout << "Ievadiet kursa kodu (1-100):";
        int code;
        cin >> code;
        course.setCode(code);

        courses.push_back(course);

        cout << "Vai turpinat? (y/n):";
        char cont;
        cin >> cont;

        if (::tolower(cont) == 'n') {
            break;
        }
    }
}

int main() {
    list<Course> courses;
    //getCourses(courses);

    Course course;
    course.setName("123455667890");
    course.setCreditPointCount(255);
    course.setPart('A');
    course.setCode(1);

    courses.push_back(course);

    Course course1;
    course1.setName("123455667890");
    course1.setCreditPointCount(255);
    course1.setPart('A');
    course1.setCode(2);


    Course course2;
    course2.setName("123455667890");
    course2.setCreditPointCount(255);
    course2.setPart('A');
    course2.setCode(4);

    courses.push_back(course1);
    courses.push_back(course2);



    cout << "Saglabāšana...\n";

    fstream fs;
    fs.open("data.bin", ios::out | ios::binary);


    for (Course course: courses) {
        int size = course.getSerializedDataSize();
        fs.seekp(size * (course.getCode() - 1));

        char *buffer = new char[size];
        course.serialize(buffer);
        fs.write(buffer, size);
    }
    fs.close();


    cout << "Ieladēšana...\n";
    fs.open("data.bin", ios::in | ios::binary);







    // cout << course.getSerializedDataSize();

    return 0;
}