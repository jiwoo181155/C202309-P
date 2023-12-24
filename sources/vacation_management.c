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
} //휴가 구조체에 동적 메모리 재할당해주는 함수

void ResizeLeaveTable() {
  if (num_leave == leave_capacity) {
    leave_capacity =
        (leave_capacity == 0) ? INITIAL_CAPACITY : leave_capacity * 2;
    LeaveTable = realloc(LeaveTable, leave_capacity * sizeof(struct AnnualLeave));
    if (LeaveTable == NULL) {
      printf("연차 구조체 배열의 메모리 할당 실패\n");
      exit(EXIT_FAILURE);
    }
  }
}  //연차 구조체에 동적 메모리 재할당해주는 함수

void ManageVacation() {
  char employee_name[50];
  printf("휴가자의 이름을 입력하세요: ");
  scanf_s("%s", employee_name, (int)sizeof(employee_name));

  int employeeIndex = FindPerson(EmployeeTable, num_people, employee_name);

  if (employeeIndex == -1) {
    printf("해당 사원은 존재하지 않습니다.\n");
    return;
  }

  ResizeVacationTable();

  printf("휴가 출발일을 입력하세요 (ex: 1900/01/01): ");
  scanf_s("%s", VacationTable[num_vacation].start_date,
          (int)sizeof(VacationTable[num_vacation].start_date));

  printf("휴가 복귀일을 입력하세요 (ex: 1900/01/01): ");
  scanf_s("%s", VacationTable[num_vacation].return_date,
          (int)sizeof(VacationTable[num_vacation].return_date));

  printf("휴가 기간을 입력하세요 (일수): ");
  scanf_s("%d", &VacationTable[num_vacation].duration);

  strcpy_s(VacationTable[num_vacation].employee_name,
           sizeof(VacationTable[num_vacation].employee_name), employee_name);

   int remainingLeaveDays =
      LeaveTable[num_vacation].total_leave_days - VacationTable[num_vacation].duration;

  if (remainingLeaveDays < 0) {
    printf("남은 연차일수가 부족합니다.\n");
    return;
  }

  // 연차 테이블 업데이트
  LeaveTable[num_vacation].remaining_leave_days = remainingLeaveDays;

  num_vacation++;

  printf("%s님의 휴가 정보가 저장되었습니다.\n", employee_name);
}

void PrintVacation(const struct VacationData *table, int num_vacation) {
  for (int i = 0; i < num_vacation; i++) {
    printf("-------------------------------\n");
    printf("이름: %s\n", table[i].employee_name);
    printf("휴가 출발일: %s\n", table[i].start_date);
    printf("휴가 복귀일: %s\n", table[i].return_date);
    printf("휴가 기간: %d 일\n", table[i].duration);
    printf("-------------------------------\n");
  }
}

void ReturnFromVacation(const char *name) {
  int TargetName_Vacation[50];
  printf("\n휴가 복귀한 사원의 이름을 입력하세요: ");
  scanf_s("%s", TargetName_Vacation, (int)sizeof(TargetName_Vacation));
  int index = FindPerson(VacationTable, num_vacation, TargetName_Vacation);
  if (index != -1) {
    // 휴가 명단에서 해당 사원의 정보를 삭제
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
    printf("%s님의 휴가 복귀 처리가 완료되었습니다.\n", name);
  } else {
    printf("%s님은 휴가 명단에 없는 사원입니다. 복귀 처리를 할 수 없습니다.\n",
           name);
  }
}

void InitializeAnnualLeave(const char *name) {
  ResizeLeaveTable();
  strcpy_s(LeaveTable[num_leave].employee_name,
           sizeof(LeaveTable[num_leave].employee_name), name);
  LeaveTable[num_leave].total_leave_days = 0;      // 총 연차일수 초기화
  LeaveTable[num_leave].remaining_leave_days = 0;  // 남은 연차일수 초기화
  num_leave++;
}

void PrintAnnualLeave() {
  printf("사원들의 연차 명단:\n");
  for (int i = 0; i < num_leave; ++i) {
    printf("-------------------------------\n");
    printf("이름: %s\n", LeaveTable[i].employee_name);
    printf("총 연차일수: %d\n", LeaveTable[i].total_leave_days);
    printf("남은 연차일수: %d\n", LeaveTable[i].remaining_leave_days);
    printf("-------------------------------\n");
  }
} //연차 구조체 출력 함수

void SetTotalLeaveDays() {
  printf("모든 사원의 총 연차일수를 입력하세요: ");
  int total_days;
  scanf_s("%d", &total_days);

  for (int i = 0; i < num_leave; ++i) {
    LeaveTable[i].total_leave_days = total_days;
    LeaveTable[i].remaining_leave_days = total_days;
  }

  printf("총 연차일수가 일괄 입력되었습니다.\n");
} //총 연차일수 일괄입력 함수

void FreeMemory_Vacation() { free(VacationTable); }
void FreeMemory_AnnualLeave() { free(LeaveTable); }