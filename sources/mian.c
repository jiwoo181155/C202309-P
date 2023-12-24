#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"
#include "resigned_employee.h"
#include "vacation_management.h"

int main() {
  EmployeeTable = malloc(INITIAL_CAPACITY * sizeof(struct EmployData));
  if (EmployeeTable == NULL) {
    printf("�޸� �Ҵ� ����\n");
    return EXIT_FAILURE;
  }
  capacity = INITIAL_CAPACITY;

  ResignedTable = malloc(INITIAL_CAPACITY * sizeof(struct ResignedData));
  if (ResignedTable == NULL) {
    printf("�޸� �Ҵ� ����\n");
    return EXIT_FAILURE;
  }
  resigned_capacity = INITIAL_CAPACITY;  // �ʱ�ȭ �߰�

  while (1) {
    int choice = -1;
    int choice_employee = -1;
    int choice_resigned = -1;
    int choice_vacation = -1;
    int choice_leave_menu = -1;
    int roof_employee = -1;
    int roof_resigned = -1;
    int roof_vacation = -1;
    int roof_leave = -1;
    printf("-------------------------------\n");
    printf("         <Main Menu>\n");
    printf("����ϴ� �޴��� �Է����ּ���.��\n");
    printf("-------------------------------\n");
    printf("1.��� ����\n2.��� ����\n3.�ް� ����\n4.����\n");
    printf("-------------------------------\n");
    printf("�޴�: ");
    scanf_s("%d", &choice);
    printf("-------------------------------\n");
    switch (choice) {
      case 1:
        while (roof_employee) {
          printf("-------------------------------\n");
          printf("         <��� �޴�>\n");
          printf("����ϴ� �޴��� �Է����ּ���.��\n");
          printf("-------------------------------\n");
          printf(
              "1.��� ��� �ű� �߰�\n2.��� ��� ����\n3.��� ��� "
              "����\n4.���θ޴��� ���ư���\n");
          printf("-------------------------------\n");
          printf("�޴�: ");
          scanf_s("%d", &choice_employee);
          printf("-------------------------------\n");
          switch (choice_employee) {
            case 1:
              AddEmployee(EmployeeTable, &num_people); //�űԻ�� �߰��ϱ�
              break;
            case 2:
              UpdateEmployee(EmployeeTable, num_people); //��� ���� �����ϱ�
              break;
            case 3:
              PrintEmployee(EmployeeTable, num_people); //��� ��� ����ϱ�
              break;
            case 4:
              roof_employee = 0; //���θ޴��� ���ư���
              break;
            default:
              printf("�߸��� �޴� �����Դϴ�.\n");
          }
        }
        break;
      case 2:
        while (roof_resigned) {
          printf("-------------------------------\n");
          printf("         <��� �޴�>\n");
          printf("����ϴ� �޴��� �Է����ּ���.��\n");
          printf("-------------------------------\n");
          printf(
              "1.����� ��� �̵�\n2.����� ��� ����\n3.���θ޴��� "
              "���ư���\n");
          printf("-------------------------------\n");
          printf("�޴�: ");
          scanf_s("%d", &choice_resigned);
          printf("-------------------------------\n");
          switch (choice_resigned) {
            case 1:
              MoveToResigned(EmployeeTable, &num_people); //����� ������� �̵�
              break;
            case 2:
              PrintResigned(ResignedTable, num_resigned); //����� ��� ���
              break;
            case 3:
              roof_resigned = 0; //���θ޴��� ���ư���
              break;
            default:
              printf("�߸��� �޴� �����Դϴ�.\n");
          }
        }
        break;
      case 3:
        while (roof_vacation) {
          printf("-------------------------------\n");
          printf("         <�ް� �޴�>\n");
          printf("����ϴ� �޴��� �Է����ּ���.��\n");
          printf("-------------------------------\n");
          printf("1.�ް� ����\n2.�ް� ��� ����\n3.�ް��� ����ó��\n4.���� ����\n5.���θ޴��� ���ư���\n");
          printf("-------------------------------\n");
          printf("�޴�: ");
          scanf_s("%d", &choice_vacation); //����ڰ� �� �޴� ���� �޾Ƽ� ����
          printf("-------------------------------\n");
          switch (choice_vacation) {
            case 1:
              ManageVacation();  //�ް� ���� ��� ȣ��
              break;
            case 2:
              PrintVacation(VacationTable,
                            num_vacation);  //�ް� ��� ��� ��� ȣ��
              break;
            case 3:
              ReturnFromVacation(EmployeeTable, num_people); //�ް��� ����ó�����=>�ް��� ��ܿ��� ����
              break;
            case 4: //�������
              while (roof_leave) {
                printf("-------------------------------\n");
                printf("         <���� �޴�>\n");
                printf("����ϴ� �޴��� �Է����ּ���.��\n");
                printf("-------------------------------\n");
                printf("1.�� �����ϼ� �ϰ� �Է��ϱ�\n2.������� ���� ��� ����\n3.������\n");
                printf("-------------------------------\n");
                printf("�޴�: ");
                scanf_s("%d", &choice_leave_menu);
                printf("-------------------------------\n");
                switch (choice_leave_menu) {
                  case 1:
                    SetTotalLeaveDays(); //�� �����ϼ�(�⺻ ����)�ϰ� �Է�
                    break;
                  case 2:
                    PrintAnnualLeave(); //������� ���
                    break;
                  case 3:
                    roof_leave = 0; //���� �޴��� ���ư���
                    break;
                  default:
                    printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
                }
              }
              roof_leave = 1;
              break;
            case 5:
              roof_vacation = 0; //���� �޴��� ����
              break;
            default:
              printf("�߸��� �޴� �����Դϴ�.\n");
          }
        }
        break;
      case 4:
        FreeMemory_Employee();
        FreeMemory_ResignedEmployee();
        FreeMemory_AnnualLeave();  //���� �޸� �Ҵ� ����
        printf("���α׷��� �����մϴ�.");
        return 0;  // ����
        break;
      default:
        printf("�߸��� �޴� �����Դϴ�.\n");
    }
  }
}