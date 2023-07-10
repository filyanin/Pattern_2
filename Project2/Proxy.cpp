// �������� ������� �������� � ����������� �������� � ������� �����������.
// ������ ������� ������ ����������� ����������, �, ������, ������ ��� ������� ����������, � �� ����� ��� ����������� ��� � ������ � ������� ������������ ������ � ��� �� ����������.
// � ����� ������ ���� Proxy - �������� ������. � ���� ����� ������ ����������, ���������� � ������������ ������.
// RealObject - ����������� ������, ������� ����������� ��� � ������.


// ��������� ��� �������� ������ �� ������� �������
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

class E_journal{ //����������� ������
public :
    E_journal(){}
    void AddStudentsGrades(StudentGrade student) {
        //���������� ������ ��������� � ����
    }
};

class P_journal { //�������� ������
public:
    void AddGrades(StudentGrade grade) {    //���������� ������
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

            std::cout << "��������, �������� ��� ������(1), �����(2), ��� �� ��������� ������ (3)" << std::endl;
            int choose;
            std::cin >> choose;
            switch (choose)
            {
                case 1:
                    e_j.AddStudentsGrades(*i);
                    grades.erase(i);
                    break;
                //case 2:
                    //���������� ����� ����� ������
            default:
                break;
            }
            
        }
    }
    void DeleteGrades() {
        //���������� ����� � �������� ������
    }

    void ChangeGrades() {
        //���������� ����������� ������
    }

private:
    std::vector<StudentGrade> grades;
    int size;
};