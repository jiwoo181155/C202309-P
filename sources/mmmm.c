#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mainheader.h"

int main() {
  EmployeeTable = malloc(INITIAL_CAPACITY * sizeof(struct EmployData));
  if (EmployeeTable == NULL) {
    printf("�޸� �Ҵ� ����\n");
    return EXIT_FAILURE;
  }
  capacity = INITIAL_CAPACITY;

  while (1) {
    int choice = -1;
    printf("-------------------------------\n");
    printf("���ϴ� �޴��� �Է����ּ���.\n");
    printf("1.��� ��� �ű� �߰�\n2.��� ��� ����\n3.��� ��� ����\n");
    printf("4.����� ��� �̵�\n5.����� ��� ����\n");
    printf("6.�ް��� ��� �߰�\n7.�ް��� ��� ����\n8.���� ���� ����\n");
    printf("9.����\n");
    printf("-------------------------------\n");
    printf("�޴�: ");
    scanf_s("%d", &choice);

    switch (choice) {
      case 1:
        AddEmployee(EmployeeTable, &num_people);
        break;
      case 2:
        UpdateEmployee(EmployeeTable, num_people);
        break;
      case 3:
        PrintEmployee(EmployeeTable, num_people);
        break;
      case 9:
        FreeMemory();
        printf("���α׷��� �����մϴ�.");
        return 0;  // ����
      default:
        printf("�߸��� �޴� �����Դϴ�.\n");
    }
  }
}