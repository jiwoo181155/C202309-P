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



int FindPerson(struct EmployData Employeetable[], int num_people,
               const char *name) {
  for (int i = 0; i < num_people; ++i) {
    if (strcmp(Employeetable[i].employ_name, name) == 0) {
      return i;
    }
  }
  return -1;  // ã�� ���� ��� -1 ��ȯ
}

int main() {
  int num_people = 0;
  while (1) {
    int choice = -1;
    printf("-------------------------\n");
    printf("���ϴ� �޴��� �Է����ּ���.\n");
    printf("1.��� ��� �ű� �߰�\n");
    printf("2.��� ��� ����\n");
    printf("3.��� ��� ����\n");
    printf("4.����� ��� �̵�\n");
    printf("5.����� ��� ����\n");
    printf("6.�ް��� ��� �߰�\n");
    printf("7.�ް��� ��� ����\n");
    printf("8.���� ���� ����\n");
    printf("9.����\n");
    printf("-------------------------\n");
    printf("�޴�: ");
    scanf_s("%d", &choice);

    int end = 0;
    char TargetName[50];

    switch (choice) {
      case 1:
        printf("�߰��� ����� ���� �Է��Ͻÿ�: \n");
        int add_count;
        scanf_s("%d", &add_count);
        printf("------------------------------\n");
        struct EmployData EmployeeTable[Max_Number] = {0};
        for (int i = 0; i < add_count; i++) {
          printf("��� �̸��� �Է��ϼ���: ");
          scanf_s("%s", EmployeeTable[num_people].employ_name, 50);
          printf("����� �Ի糯¥�� �Է��ϼ���(ex:1900/01/01): ");
          scanf_s("%s", EmployeeTable[num_people].start_company, 30);
          printf("����� ���������� �Է��ϼ���: ");
          scanf_s("%s", EmployeeTable[num_people].residence, 50);
          printf("����� ������ �Է��ϼ���: ");
          scanf_s("%s", EmployeeTable[num_people].role, 20);
          printf("����� ���̸� �Է��ϼ���: ");
          scanf_s("%d", &EmployeeTable[num_people].age);
          printf("------------------------------\n");
          num_people++;
        }
        break;
      case 2:
        printf("\n������ ����� �̸��� �Է��ϼ���: ");
        scanf_s("%s", TargetName,(int)sizeof(TargetName));

        int peopleIndex = FindPerson(EmployeeTable, Max_Number, TargetName);

        if (peopleIndex == -1) {
          printf("\n�ش� ����� �������� �ʽ��ϴ�\n");
          break;
        }

        int choice;
        printf("��---------------------------\n");
        printf("������ �׸��� �����ϼ���:\n");
        printf("1. ����\n2. ������\n3. ����\n4. �ٹ� ����\n");
        printf(" ----------------------------��\n");
        printf("������ �׸� ��ȣ: ");
        scanf_s("%d", &choice);

        if (peopleIndex != -1) {
          // ������ �� �Է�
          int NewAge;
          char NewResidence[50];
          char NewRole[50];
          char Newstart_company[50];

          switch (choice) {
            case 1:
              printf("���ο� ���� �Է�: ");
              scanf_s("%d", &NewAge);
              EmployeeTable[peopleIndex].age = NewAge;
              break;
            case 2:
              printf("���ο� ������ �Է�: ");
              scanf_s("%s", NewResidence,(int)sizeof(NewResidence));
              strcpy_s(EmployeeTable[peopleIndex].residence,16, NewResidence);
              break;
            case 3:
              printf("���ο� ���� �Է�: ");
              scanf_s("%s", NewRole,(int)sizeof(NewRole));
              strcpy_s(EmployeeTable[peopleIndex].role,16, NewRole);
              break;
            case 4:
              printf("���ο� �ٹ� ���� �Է�: ");
              scanf_s("%s", Newstart_company, (int)sizeof(Newstart_company));
              strcpy_s(EmployeeTable[peopleIndex].start_company,16,Newstart_company);
              break;
            default:
              printf("�߸��� �����Դϴ�.\n");
          }
        } 
        break;
      case 3:
        for (int i = 0; i < num_people; i++) {
          printf("�̸�: %s\n", EmployeeTable[i].employ_name);
          printf("����: %d\n", EmployeeTable[i].age);
          printf("�Ի� ��¥: %s\n", EmployeeTable[i].start_company);
          printf("����: %s\n", EmployeeTable[i].role);
          printf("������: %s\n", EmployeeTable[i].residence);
        }
        break;
      case 9:
        end = -1;
        break;
    }
    if (end == -1) {
      printf("���α׷��� ����˴ϴ�.\n");
      break;
    }
  }
}