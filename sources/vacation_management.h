#pragma once
#ifndef VACATION_MANAGEMENT_H
#define VACATION_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VACATION_CAPACITY 10  // 초기 휴가 구조체 배열 메모리 할당 크기

struct VacationData {
  char employee_name[50];  //이름
  char start_date[30];     //
  char return_date[30];
  int duration;
};

struct AnnualLeave {
  char employee_name[50];
  int total_leave_days;
  int remaining_leave_days;
};

extern struct AnnualLeave *LeaveTable;
extern int num_leave;
extern int leave_capacity;

extern struct VacationData *VacationTable;
extern int num_vacation;
extern int vacation_capacity;

void ResizeVacationTable();
void ManageVacation();
void PrintVacation(const struct VacationData *table, int num_vacation);
void FreeMemory_Vacation();
void ReturnFromVacation(const char *name);

void InitializeAnnualLeave(const char *name);
void PrintAnnualLeave();
void SetTotalLeaveDays();
void ResizeLeaveTable();
void FreeMemory_AnnualLeave();
#endif  