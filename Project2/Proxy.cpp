// Школьный учитель работает с электронным журналом и обычным параллельно.
// Однако обычный журнал заполняется ежеждневно, и, скорее, служит для учителя черновиком, в то время как электронный раз в неделю и учителя предпочитают ничего в нем не исправлять.
// В таком случае клас Proxy - бумажный журнал. В него можно писать карандашем, исправлять и переписывать оценки.
// RealObject - электронный журнал, который обновляется раз в неделю.


// Структура для хранения данных об оценках ученика
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

struct StudentGrade {
    std::string name;
    std::vector<int> grades;
};

void printStudentGrade(StudentGrade student) {
    std::cout << student.name << std::endl;
    int size = student.grades.size();
    for (int i = 0; i < size; i++) {
        printf("% .4", i);
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        printf("% .4", student.grades[i]);
    }
}

class E_journal{ //электронный журнал
public :
    E_journal(){}
    void AddStudentsGrades(StudentGrade student) {
        //происходит запись элементов в файл
    }
};

class P_journal { //бумажный журнал
public:
    void AddGrades(StudentGrade grade) {    //добавление оценки
        for (int i = 0; i < size; i++) {
            if (grades[i].name == grade.name) {
                int grades_size;
                for (int j = 0; j < grades_size; j++) {
                    grades[i].grades.push_back(grade.grades[j]);
                }
            }
            else
            {
                grades.push_back(grade);
            }
        }
    };
    void AddGradesToE_J() {
        E_journal e_j;
        std::vector<StudentGrade>::iterator i;
        for (i = grades.begin(); i < grades.end(); i++) {
            printStudentGrade(*i);

            std::cout << "Выберите, добавить все оценки(1), часть(2), или не добавлять совсем (3)" << std::endl;
            int choose;
            std::cin >> choose;
            switch (choose)
            {
                case 1:
                    e_j.AddStudentsGrades(*i);
                    grades.erase(i);
                    break;
                //case 2:
                    //происходит выбор части оценок
            default:
                break;
            }
            
        }
    }
    void DeleteGrades() {
        //происходит выбор и удаление оценок
    }

    void ChangeGrades() {
        //происходит исправление оценок
    }

private:
    std::vector<StudentGrade> grades;
    int size;
};