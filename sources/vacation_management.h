#pragma once
#ifndef VACATION_MANAGEMENT_H
#define VACATION_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VACATION_CAPACITY 10  // 초기 휴가 구조체 배열 메모리 할당 크기

struct VacationData {
  char employee_name[50];  
  char start_date[30];   
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

void ResizeVacationTable(); //휴가구조체 메모리 동적할당 함수
void ManageVacation(); //휴가 명단 추가
void PrintVacation(const struct VacationData *table, int num_vacation); //휴가자 명단 출력
void FreeMemory_Vacation(); //동적메모리 할당 해제
void ReturnFromVacation(const char *name); //휴가 복귀처리 함수

void InitializeAnnualLeave(const char *name); //신규 사원추가시 연차명단에도 해당 사원이름 추가
void PrintAnnualLeave(); //연차명단 출력함수
void SetTotalLeaveDays(); //총 연차일수 입력 함수
void ResizeLeaveTable(); //연차구조체 메모리 동적할당 함수
void FreeMemory_AnnualLeave(); //동적메모리 할당 해제
#endif  