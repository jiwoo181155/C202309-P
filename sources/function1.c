#include <stdio.h>

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char living_area[50];
  char role[20];
  int age;
};

int main() { 
	struct EmployData EmployeeTable[20] = {0};
    for (int i = 0; i < 20; i++) {
          printf("��� �̸��� �Է��ϼ���: ");
          scanf_s("%s", EmployeeTable[i].employ_name, 50);
          printf("����� �Ի糯¥�� �Է��ϼ���(ex:1900/01/01): ");
          scanf_s("%s", EmployeeTable[i].start_company, 30);
          printf("����� ���������� �Է��ϼ���: ");
          scanf_s("%s", EmployeeTable[i].living_area, 50);
          printf("����� ������ �Է��ϼ���: ");
          scanf_s("%s", EmployeeTable[i].role, 20);
          printf("����� ���̸� �Է��ϼ���: ");
          scanf_s("%d", &EmployeeTable[i].age);
  }
   
}