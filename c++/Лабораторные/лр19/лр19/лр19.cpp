

#include <map>
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <string> 
using namespace std;

struct student
{
    string fio;
    int year;
    int group;
    map <string, int> Marks;

    float sr()
    {
        return (Marks["fizika"] + Marks["matem"] + Marks["infa"] + Marks["himia"]) / 4.0;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    student Max;
    Max.fio = "Max";
    Max.year = 11;
    Max.group = 1;
    Max.Marks = {
             {"fizika", 10},
             { "matem", 10 },
             { "infa", 10 },
             { "himia", 10 } };

    student Vax;
    Vax.fio = "Vax";
    Vax.year = 12;
    Vax.group = 3;
    Vax.Marks = {
             {"fizika", 9},
             { "matem", 10 },
             { "infa", 5 },
             { "himia", 4 } };

    student Lax;
    Lax.fio = "Lax";
    Lax.year = 13;
    Lax.group = 2;
    Lax.Marks = {
             {"fizika", 2},
             { "matem", 1 },
             { "infa", 4 },
             { "himia", 1 } };

    student stud[3] = { Max, Vax, Lax };


    ofstream out;
    out.open("RESULT.txt");

    if (out.is_open()) {
        bool flag = false;
        out << "Студенты с оценкой 9 по физике и 10 по информатике: " << endl;
        for (int i = 0; i < 3; i++) {
            if (stud[i].Marks["fizika"] == 9 && stud[i].Marks["matem"] == 10) {
                out << stud[i].fio << " " << stud[i].year << endl;
                flag = true;
            }
        if(flag == false) {
            out << "Нет такого студента\n";

            }
           
        }

        out.close();
        system("pause");
        return 0;
    }
}
