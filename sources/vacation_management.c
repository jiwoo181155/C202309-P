#include "vacation_management.h"
#include "employee.h"

struct VacationData *VacationTable = NULL;
int num_vacation = 0;
int vacation_capacity = 0;

struct AnnualLeave *LeaveTable = NULL;
int num_leave = 0;
int leave_capacity = 0;

void ResizeVacationTable() {
  if (num_vacation == vacation_capacity) {
    vacation_capacity =
        (vacation_capacity == 0) ? VACATION_CAPACITY : vacation_capacity * 2;
    VacationTable =
        realloc(VacationTable, vacation_capacity * sizeof(struct VacationData));
    if (VacationTable == NULL) {
      perror("Memory allocation failed");
      exit(EXIT_FAILURE);
    }
  }
} //�ް� ����ü�� ���� �޸� ���Ҵ����ִ� �Լ�

void ResizeLeaveTable() {
  if (num_leave == leave_capacity) {
    leave_capacity =
        (leave_capacity == 0) ? INITIAL_CAPACITY : leave_capacity * 2;
    LeaveTable = realloc(LeaveTable, leave_capacity * sizeof(struct AnnualLeave));
    if (LeaveTable == NULL) {
      printf("���� ����ü �迭�� �޸� �Ҵ� ����\n");
      exit(EXIT_FAILURE);
    }
  }
}  //���� ����ü�� ���� �޸� ���Ҵ����ִ� �Լ�

void ManageVacation() {
  char employee_name[50];
  printf("�ް����� �̸��� �Է��ϼ���: ");
  scanf_s("%s", employee_name, (int)sizeof(employee_name));

  int employeeIndex = FindPerson(EmployeeTable, num_people, employee_name);

  if (employeeIndex == -1) {
    printf("�ش� ����� �������� �ʽ��ϴ�.\n");
    return;
  }

  ResizeVacationTable();

  printf("�ް� ������� �Է��ϼ��� (ex: 1900/01/01): ");
  scanf_s("%s", VacationTable[num_vacation].start_date,
          (int)sizeof(VacationTable[num_vacation].start_date));

  printf("�ް� �������� �Է��ϼ��� (ex: 1900/01/01): ");
  scanf_s("%s", VacationTable[num_vacation].return_date,
          (int)sizeof(VacationTable[num_vacation].return_date));

  printf("�ް� �Ⱓ�� �Է��ϼ��� (�ϼ�): ");
  scanf_s("%d", &VacationTable[num_vacation].duration);

  strcpy_s(VacationTable[num_vacation].employee_name,
           sizeof(VacationTable[num_vacation].employee_name), employee_name);

   int remainingLeaveDays =
      LeaveTable[num_vacation].total_leave_days - VacationTable[num_vacation].duration;

  if (remainingLeaveDays < 0) {
    printf("���� �����ϼ��� �����մϴ�.\n");
    return;
  }

  // ���� ���̺� ������Ʈ
  LeaveTable[num_vacation].remaining_leave_days = remainingLeaveDays;

  num_vacation++;

  printf("%s���� �ް� ������ ����Ǿ����ϴ�.\n", employee_name);
}

void PrintVacation(const struct VacationData *table, int num_vacation) {
  for (int i = 0; i < num_vacation; i++) {
    printf("-------------------------------\n");
    printf("�̸�: %s\n", table[i].employee_name);
    printf("�ް� �����: %s\n", table[i].start_date);
    printf("�ް� ������: %s\n", table[i].return_date);
    printf("�ް� �Ⱓ: %d ��\n", table[i].duration);
    printf("-------------------------------\n");
  }
}

void ReturnFromVacation(const char *name) {
  int TargetName_Vacation[50];
  printf("\n�ް� ������ ����� �̸��� �Է��ϼ���: ");
  scanf_s("%s", TargetName_Vacation, (int)sizeof(TargetName_Vacation));
  int index = FindPerson(VacationTable, num_vacation, TargetName_Vacation);
  if (index != -1) {
    // �ް� ��ܿ��� �ش� ����� ������ ����
    for (int i = index; i < num_vacation - 1; ++i) {
      strcpy_s(VacationTable[i].employee_name,
               sizeof(VacationTable[i].employee_name),
               VacationTable[i + 1].employee_name);
      strcpy_s(VacationTable[i].start_date, sizeof(VacationTable[i].start_date),
               VacationTable[i + 1].start_date);
      strcpy_s(VacationTable[i].return_date, sizeof(VacationTable[i].return_date),
               VacationTable[i + 1].return_date);
      VacationTable[i].duration = VacationTable[i + 1].duration;
    }
    --num_vacation;
    printf("%s���� �ް� ���� ó���� �Ϸ�Ǿ����ϴ�.\n", name);
  } else {
    printf("%s���� �ް� ��ܿ� ���� ����Դϴ�. ���� ó���� �� �� �����ϴ�.\n",
           name);
  }
}

void InitializeAnnualLeave(const char *name) {
  ResizeLeaveTable();
  strcpy_s(LeaveTable[num_leave].employee_name,
           sizeof(LeaveTable[num_leave].employee_name), name);
  LeaveTable[num_leave].total_leave_days = 0;      // �� �����ϼ� �ʱ�ȭ
  LeaveTable[num_leave].remaining_leave_days = 0;  // ���� �����ϼ� �ʱ�ȭ
  num_leave++;
}

void PrintAnnualLeave() {
  printf("������� ���� ���:\n");
  for (int i = 0; i < num_leave; ++i) {
    printf("-------------------------------\n");
    printf("�̸�: %s\n", LeaveTable[i].employee_name);
    printf("�� �����ϼ�: %d\n", LeaveTable[i].total_leave_days);
    printf("���� �����ϼ�: %d\n", LeaveTable[i].remaining_leave_days);
    printf("-------------------------------\n");
  }
} //���� ����ü ��� �Լ�

void SetTotalLeaveDays() {
  printf("��� ����� �� �����ϼ��� �Է��ϼ���: ");
  int total_days;
  scanf_s("%d", &total_days);

  for (int i = 0; i < num_leave; ++i) {
    LeaveTable[i].total_leave_days = total_days;
    LeaveTable[i].remaining_leave_days = total_days;
  }

  printf("�� �����ϼ��� �ϰ� �ԷµǾ����ϴ�.\n");
} //�� �����ϼ� �ϰ��Է� �Լ�

void FreeMemory_Vacation() { free(VacationTable); }
void FreeMemory_AnnualLeave() { free(LeaveTable); }