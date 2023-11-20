#include <stdio.h>
#define Max_Number 100

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};

struct EmployData EmployeeTable[Max_Number];

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

    int num_people;
    char TargetName[50];

    switch (choice) {
      case 1:
        printf("�߰��� ����� ���� �Է��Ͻÿ�: \n");
        scanf_s("%d", &num_people);
        printf("------------------------------\n");
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
          printf("------------------------------\n");
        }
        break;
      case 2:
        printf("\n������ ����� �̸��� �Է��ϼ���: ");
        scanf_s("%s", TargetName);

        int choice;
        printf("------------------------------");
        printf("������ �׸��� �����ϼ���:\n");
        printf("1. ����\n");
        printf("2. ������\n");
        printf("3. ����\n");
        printf("4. �ٹ� ����\n");
        printf("------------------------------");
        scanf_s("%d", &choice);

        int peopleIndex = FindPerson(EmployeeTable, Max_Number, TargetName);

        if (peopleIndex != -1) {
          // ������ �� �Է�
          int NewAge;
          char NewResidence[50];
          char NewRole[50];
          char Newstart_company;

          switch (choice) {
            case 1:
              printf("���ο� ���� �Է�: ");
              scanf_s("%d", &NewAge);
              EmployeeTable[peopleIndex].age = NewAge;
              break;
            case 2:
              printf("���ο� ������ �Է�: ");
              scanf_s("%s", NewResidence);
              strcpy(EmployeeTable[peopleIndex].residence, NewResidence);
              break;
            case 3:
              printf("���ο� ���� �Է�: ");
              scanf_s("%s", NewRole);
              strcpy(EmployeeTable[peopleIndex].role, NewRole);
              break;
            case 4:
              printf("���ο� �ٹ� ���� �Է�: ");
              scanf_s("%d", &Newstart_company);
              strcpy(EmployeeTable[peopleIndex].start_company,Newstart_company);
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
    }
  }
}