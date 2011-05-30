#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[]) {
time_t rawtime;
struct tm * timeinfo;
time(&rawtime);
timeinfo = localtime(&rawtime);
if((timeinfo->tm_hour+timeinfo->tm_min)==0) system("echo \"\" > summary-1D");
if((timeinfo->tm_mday+timeinfo->tm_min)==1) system("echo \"\" > summary-1M");
return 0;
}