#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <linux/rtc.h>




int main() {

int hour[50];

int htime;

int n=0;

int i;

FILE *ls = popen("/usr/sbin/hwclock -r", "r");
	char buf[256];
        while (fgets(buf, sizeof(buf), ls) != 0) {
        //printf("System Time : %s", buf);
            for (i=0; i < 50; i++) {
       // printf("%c", buf[i]);

                 hour[n] = buf[i];
                  n = n + 1;
    }
}


pclose(ls);

printf("Testing Sysclock with Char %c%c%c%c\n" , hour[16],hour[17],hour[19],hour[20]);

int r = hour[16] - '0';
int x = hour[17] - '0';
int y = hour[19] - '0';
int z = hour[20] - '0';
htime= r * 1000 + x * 100 + y * 10 + z;

printf("%i", htime);

}
