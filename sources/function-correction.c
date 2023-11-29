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

int FindPerson(struct EmployData Employeetable[], int num_people, const char *name) {
  for (int i = 0; i < num_people; ++i) {
    if (strcmp(Employeetable[i].employ_name, name) == 0) {
      return i;
    }
  }
  return -1;  // ã�� ���� ��� -1 ��ȯ
}

int main() {
  char TargetName[50];
  printf("\n������ ����� �̸��� �Է��ϼ���: ");
  scanf("%s", TargetName);

  int choice;
  printf("------------------------------");
  printf("������ �׸��� �����ϼ���:\n");
  printf("1. ����\n");
  printf("2. ������\n");
  printf("3. ����\n");
  printf("4. �ٹ� ����\n");
  printf("------------------------------");
  scanf("%d", &choice);

  int peopleIndex = FindPerson(Employeetable, Max_Number, TargetName);

  if (peopleIndex != -1) {
    // ������ �� �Է�
    int NewAge;
    char NewResidence[50];
    char NewRole[50];
    char Newstart_company;

    switch (choice) {
      case 1:
        printf("���ο� ���� �Է�: ");
        scanf("%d", &NewAge);
        Employeetable[peopleIndex].age = NewAge;
        break;
      case 2:
        printf("���ο� ������ �Է�: ");
        scanf("%s", NewResidence);
        strcpy(Employeetable[peopleIndex].residence, NewResidence);
        break;
      case 3:
        printf("���ο� ���� �Է�: ");
        scanf("%s", NewRole);
        strcpy(Employeetable[peopleIndex].role, NewRole);
        break;
      case 4:
        printf("���ο� �ٹ� ���� �Է�: ");
        scanf("%d", &Newstart_company);
        Employeetable[peopleIndex].start_company = Newstart_company;
        break;
      default:
        printf("�߸��� �����Դϴ�.\n");
    }
  }