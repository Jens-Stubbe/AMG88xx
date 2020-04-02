#pragma once
#include <iostream>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

namespace i2c{
  class I2C{
    public:
      I2C();
      bool compose(char buffer[],int length);
      bool consult(char buffer[],int length);
      void openI2C(int I2c_chip_address);

    private:
      int file;
      int I2c_chip_address;
      std::string filename;
  };
}

