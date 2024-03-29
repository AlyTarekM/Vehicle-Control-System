/*
 * Vehicle Control System Project
 *
 *  Created on: August , 2022
 *      Author: Aly Tarek
 */


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
	int speed;
	int roomTemp;
	char tempControl[5];
	char AC_State[5];
	int engineTemp;
	char engState[5];

}Car;
void SensorMenu(int *,Car *);
void AC_Function(Car *);
void display_State(Car *);
void engineTemp_Control(Car *);
void SpeedCheck(Car *);

int main(void) {
	char input;
	int engState=0;
	Car vehicle;
	vehicle.speed=35;
	vehicle.roomTemp=35;
	strcpy(vehicle.tempControl,"OFF");
	strcpy(vehicle.AC_State,"OFF");
	strcpy(vehicle.engState,"OFF");
	vehicle.engineTemp=90;
	while(1){
		printf("a. Turn on the vehicle engine\n");
			printf("b. Turn off the vehicle engine\n");
			printf("c. Quit the system\n\n");
			fflush(stdout);
			scanf(" %c",&input);
		if(input=='b'){
			printf("Turn Off Vehicle Engine\n\n");
			continue;
		}
		else if(input=='a'){
			engState=1;
			strcpy(vehicle.engState,"ON");
			SensorMenu(&engState,&vehicle);
			continue;
		}
		else printf("Quit The System");
		fflush(stdout);
		break;
	}

	return 0;
}
void SensorMenu(int *engState,Car *vehicle){
	char SensorInput,color;
	while(*engState==1){
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
	printf("d. Set the engine temperature\n");
	fflush(stdout);
	scanf(" %c",&SensorInput);
	while(1){
		if(SensorInput=='a'){
			*engState=0;
			strcpy(vehicle->engState,"OFF");
			break;
		}
		else if(SensorInput=='b'){
			printf("Enter Required Color:\n");
			fflush(stdout);
			scanf(" %c",&color);
			if(color=='g'|| color=='G'){
				vehicle->speed=100;

			}
			else if(color=='o'|| color=='O'){
				vehicle->speed=30;

			}
			else {
				vehicle->speed=0;

			}
		}
		else if(SensorInput=='c'){
			printf("Enter required room temperature:\n");
			fflush(stdout);
			scanf("%d",&vehicle->roomTemp);
			AC_Function(vehicle);

			}
		else if(SensorInput=='d'){
			printf("Enter engine temperature:\n");
			fflush(stdout);
			scanf("%d",&vehicle->engineTemp);
			engineTemp_Control(vehicle);
		}


		SpeedCheck(vehicle);
		display_State(vehicle);
					break;

		}

	}

	return;
}
void display_State(Car *vehicle){
	printf("Engine is %s\n",vehicle->engState);
	printf("AC is %s\n",vehicle->AC_State);
	printf("Vehicle Speed: %d km/hr\n",vehicle->speed);
	printf("Room Temperature: %d C\n",vehicle->roomTemp);
	printf("Engine Temp Controller: %s\n ",vehicle->tempControl);
	printf("Engine Temperature: %d\n\n",vehicle->engineTemp);
}
void AC_Function(Car *vehicle){
	if(vehicle->roomTemp<10){
		vehicle->roomTemp=20;
		strcpy(vehicle->AC_State,"ON");
	}
	else if(vehicle->roomTemp>30){
		vehicle->roomTemp=20;
		strcpy(vehicle->AC_State,"ON");
	}
	else {
		strcpy(vehicle->AC_State,"OFF");
	}
}

void engineTemp_Control(Car *vehicle){
	if(vehicle->engineTemp<100){
		//turn control ON
		strcpy(vehicle->tempControl,"ON");
		vehicle->engineTemp=125;
	}
	else if(vehicle->engineTemp>150){
		//turn Control ON
		strcpy(vehicle->tempControl,"ON");
		vehicle->engineTemp=125;
	}
	else{
		//turn control OFF
		strcpy(vehicle->tempControl,"OFF");
	}
}

void SpeedCheck(Car *vehicle){
	if(vehicle->speed==30){
		strcpy(vehicle->AC_State,"ON");
		vehicle->roomTemp=vehicle->roomTemp*5/4+1;
		strcpy(vehicle->tempControl,"ON");
		vehicle->engineTemp=vehicle->engineTemp*5/4+1;
	}
}
