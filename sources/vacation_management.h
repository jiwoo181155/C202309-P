#pragma once
#ifndef VACATION_MANAGEMENT_H
#define VACATION_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VACATION_CAPACITY 10  // �ʱ� �ް� ����ü �迭 �޸� �Ҵ� ũ��

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

void ResizeVacationTable(); //�ް�����ü �޸� �����Ҵ� �Լ�
void ManageVacation(); //�ް� ��� �߰�
void PrintVacation(const struct VacationData *table, int num_vacation); //�ް��� ��� ���
void FreeMemory_Vacation(); //�����޸� �Ҵ� ����
void ReturnFromVacation(const char *name); //�ް� ����ó�� �Լ�

void InitializeAnnualLeave(const char *name); //�ű� ����߰��� ������ܿ��� �ش� ����̸� �߰�
void PrintAnnualLeave(); //������� ����Լ�
void SetTotalLeaveDays(); //�� �����ϼ� �Է� �Լ�
void ResizeLeaveTable(); //��������ü �޸� �����Ҵ� �Լ�
void FreeMemory_AnnualLeave(); //�����޸� �Ҵ� ����
#endif  