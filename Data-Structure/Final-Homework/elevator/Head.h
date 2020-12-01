#ifndef _ELEVATORHEAD_H_
#define _ELEVATORHEAD_H_

#include <stdio.h>
#include <stdlib.h>

// ʱ��
#define DoorTestTime 40         //���˽�������ʱ��
#define InOutDoorTime 20        //���ݿ��Ź���ʱ��
#define InOutPersonTime 25      //�˽�������ʱ��
#define OverTime 300            //����ͣ��ʱʱ��
#define UpAccelerateTime 15     //���������ļ���ʱ��
#define UpTime 51               //��������������ʱ��
#define UpDecelerateTime 14     //���������ļ���ʱ��
#define DownAccelerateTime 15   //�����½��ļ���ʱ��
#define DownTime 61             //�����½�������ʱ��
#define DownDecelerateTime 23   //�����½��ļ���ʱ��
#define MaxTime	10000		//�ʱ��

//����״̬
#define GoingUp 1       //��������
#define GoingDown 2     //�����½�
#define SpeedUp 3       //��������
#define SpeedDown 4     //�����½�
#define SlowUp 5        //��������
#define SlowDown 6      //�����½�
#define Idle 7          //����
#define Stop 8          //ֹͣ���ѹ���
#define DoorOpen 9      //ֹͣ�����Ѵ�
#define DoorOpening 10
#define DoorCloseing 11


#define MaxPerson 50
#define MaxFloor 5
#define BaseFloor 1

//����
typedef struct Person{
    int PersonID;
    int InFloor, OutFloor;
    int GiveUpTime, InterTime,AppearTime;
}Person;
int personnum = 0;
Person person[MaxPerson];

//ÿһ��Ľ�������
typedef struct FloorPersonIn{
    int PersonID;
    int InFloor, OutFloor;
    int AppearTime, GiveUpTime;
    struct FloorPersonIn *next;
}FloorPersonIn;
FloorPersonIn personin[5];

//�����е���
int FloorPersonOut[5][MaxPerson+1];
int outpos[5];  //������ȥ��i�������

//Activity
typedef struct Activity{
	int time;
	void(*fn)(void);
	struct Activity* next;
}Activity;

Activity activity={0,NULL,NULL};

int Time = 0;
//����
int CallUp[MaxFloor];
int CallDown[MaxFloor];
int CallCar[MaxFloor];
int Floor = BaseFloor;
int State = Idle;
int D1=0, D2=0, D3=0;


int AddQueue(int infloor, Person personi);
void AddAct(int time, void(*fn)(void));
void TestPeople();
void Input(void);
void testinout(void);
void ElevatorClose(void);
void ElevatorOpen(void);
void PeopleOut(void);
void PeopleIn(void);
int GetWhere(void);
void tofirst(void);
void ElevatorStop(void);
void ElevatorUp(void);
void ElevatorDown(void);
void ElevatorMove(void);
void Controler(void);

#endif
