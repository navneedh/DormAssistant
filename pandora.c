#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define STDIN 0

int
main(int argc, char** argv) {
    char value;
    int ret;
    printf("This is testing program for python subprocess\n");

    while ((ret = read(STDIN, &value, sizeof(value))) > 0 ) {
            printf("Read cha./aracter is %c\n", value);
            if ( value == 'q' ) break;
    }

    printf("retcode is %d errno=%d\n", ret, errno);
}
