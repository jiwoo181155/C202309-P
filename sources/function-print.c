#include <stdio.h>
#include <string.h>
#define Max_Number 100

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};

int main() {
  int num_people;
  printf("�߰��� ����� ���� �Է��Ͻÿ�: ");
  printf("------------------------------");
  scanf_s("%d", &num_people);
  struct EmployData EmployeeTable[Max_Number] = {0};
  for (int i = 0; i < num_people; i++) {
    printf("��� �̸��� �Է��ϼ���: ");
    scanf_s("%s", EmployeeTable[i].employ_name, 50);
    printf("����� �Ի糯¥�� �Է��ϼ���(ex:1900/01/01): ");
    scanf_s("%s", EmployeeTable[i].start_company, 30);
    printf("����� ���������� �Է��ϼ���: ");
    scanf_s("%s", EmployeeTable[i].residence, 50);
    printf("����� ������ �Է��ϼ���: ");
    scanf_s("%s", EmployeeTable[i].role, 20);
    printf("����� ���̸� �Է��ϼ���: ");
    scanf_s("%d", &EmployeeTable[i].age);
    printf("------------------------------");
  }

  printf("\n�����ִ� ��� ����:\n");
  for (int i = 0; i < num_people; i++) {
    printf("�̸�: %s\n", EmployeeTable[i].employ_name);
    printf("����: %d\n", EmployeeTable[i].age);
    printf("�Ի� ��¥: %s\n", EmployeeTable[i].start_company);
    printf("����: %s\n", EmployeeTable[i].role);
    printf("������: %s\n", EmployeeTable[i].residence);
  }

  return 0;
}