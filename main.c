//#define debug
#define brightfile "/sys/class/backlight/intel_backlight/brightness"
#define maxfile "/sys/class/backlight/intel_backlight/max_brightness"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	FILE *fp = NULL;
	float argVal = 0;
	
	//check arg
	if (argv[1] != NULL){
		sscanf(argv[1], "%f", &argVal);
		if (argVal > 100) {
			printf("ERROR: cannot excede 100\%\n");
			return 0;}
#ifdef debug
		printf("argument given: %f\n", argVal);
#endif
	}
	else {printf("no value given\n"); return 0;}


	//convert arg from percent to decimal
	float newVal = argVal/100;
#ifdef debug
	printf("new percent to set: %f\n", newVal);
#endif


	//check if file exists
	fp = fopen( brightfile, "r");
	if (fp != NULL) {
#ifdef debug
		printf("brightness file exists\n");
#endif
		fclose(fp);}
	else {printf("file does not exist\n"); return 0;}


	//check brightness
int getBrightness(void){
	int brightness = 0;
	char line[5];
	fp = fopen( brightfile, "r");
	if (fp != NULL) {
		fgets(line, 5, fp);
		sscanf(line, "%d", &brightness);
#ifdef debug
		printf("brightness: %d\n", brightness);
#endif
		fclose(fp);
		return brightness;
	}
	else {printf("error: could not find brightness\n"); return -1;}
}


	//check max brightness
int getMaxBrightness(void){
	int maxBrightness = 0;
	char line[5];
	fp = fopen( maxfile, "r");
	if (fp != NULL) {
		fgets(line, 5, fp);
		sscanf(line, "%d", &maxBrightness);
#ifdef debug
		printf("max brightness: %d\n", maxBrightness);
#endif
		fclose(fp);
		return maxBrightness;
	}
	else {printf("error: could not find max brightness\n"); return -1;}
}


	//set brightness
int setBrightness(int val){
	fp = fopen( brightfile, "w");
	if (fp != NULL){
#ifdef debug
		printf("setting brightness to %d\n", val);
#endif
		fprintf(fp, "%d", val);
		fclose(fp);
		return val;
	}
	else {printf("error: could not access file\n"); return -1;}
}

#ifdef debug
	printf("made it to end\n");
#endif
	
	return 0;
}
