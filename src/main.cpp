#include "AMG88xx.h"
#include <iostream>
#include <gtk/gtk.h>

using namespace amg88xx;

int main(void) {
	
  AMG88xx IR_sensor;
  IR_sensor.set_Operation_Mode(0x00);
  IR_sensor.reset();
  IR_sensor.set_FPS(0);

  while(true){
	  int initial_Register_Address = 0x80;
	  int pixel_output[16][16];
		for(uint i=0;i<16;i++){
			for(uint j=0;j<16;j++){
				int address = initial_Register_Address + (0x02 * i) + (0x02 * j);
				pixel_output[i][j] = IR_sensor.get_Pixel_Temperature(address);
				std::cout<<pixel_output[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
}
