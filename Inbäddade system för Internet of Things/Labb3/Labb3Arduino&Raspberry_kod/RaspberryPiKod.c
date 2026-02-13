#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int main() {
  int fd;
  if ((fd = serialOpen("/dev/ttyS0", 300)) < 0) {
    fprintf(stderr, "Unable to open serial device: %s\n", strerror(errno));
    return 1;
  }

  while (true) {
    while (serialDataAvail(fd)) {
      printf("data recv: %d", serialGetchar(fd));
      fflush(stdout);
    }
  }
  return 0;
}