#include <AnalogPHMeter.h>
#include <LiquidCrystal.h>
#define  SensorPin A1
#define  orneklemeAraligi 20
#define  printAraligi 2000
#define  arrayUzunlugu 40

int pHArray [arrayUzunlugu];
int pHArrayIndex = 0
LiquidCrystal lcd(12,11,5,4,3,2);
double ortalamaArray (int* arr, int sayi){
	int i;
	int  max,min;
	double ort;
	long miktar=0;
	if(sayi<=0){
	return 0;
	}
	if(sayi<5){
	for(i=0;i<sayi;i++){
		miktar+=arr[i];
		}
		ort=miktar/sayi
		return ort;
		}else{
		if(arr[0]<arr[1]){
			min=arr[0]; max=arr[1];
			}else
			min=arr[1]; max=arr[0];
			}
			for(i=2;i<sayi;i++){
			if(arr[i]<min) {
			miktar+=min;
			min=arr[i];
			}else
