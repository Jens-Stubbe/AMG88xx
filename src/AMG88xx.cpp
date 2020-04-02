#include "AMG88xx.h"

namespace amg88xx{
	AMG88xx::AMG88xx(){
		//https://cdn-learn.adafruit.com/assets/assets/000/043/261/original/Grid-EYE_SPECIFICATIONS%28Reference%29.pdf?1498680225
		i2c.openI2C(slave_address);
		}
	void AMG88xx::set_Operation_Mode(int value){
		/*
		 * [Operating Modes]
		 * 0x00 - Normal Mode
		 * 0x10 - Sleep Mode
		 * 0x20 - Stand-by mode (60s intermittence)
		 * 0x21 - Stand-by mode (10s intermittence)
		 */
		int register_address = 0x00;
		buffer[0] = register_address;
		buffer[1] = value;
		i2c.compose(buffer,sizeof(buffer));
		}
	void AMG88xx::reset(){
		int register_address = 0x01;
		buffer[0] = register_address;
		buffer[1] = 0x3F;
		i2c.compose(buffer,sizeof(buffer));
		}
	void AMG88xx::set_FPS(int value){
		/*
		 * [Frame Rates]
		 * 0 - 10 FPS
		 * 1 - 1 FPS
		 */
		int register_address = 0x02;
		buffer[0] = register_address;
		buffer[1] = 0;
		i2c.compose(buffer,sizeof(buffer));
		}
	int AMG88xx::get_Ambient_Temperature(){
		int register_address = 0x0E;
		int reading[sizeof(buffer)];
		for(uint i=0;i<sizeof(buffer);i++){
			register_address = register_address + i;
			buffer[0] = register_address;
			i2c.compose(buffer,1);
			i2c.consult(buffer,1);
			reading[i] = buffer[0];
			}
		int Ambient_Temperature = ((reading[1] << 8) | reading[0]);
		return Ambient_Temperature * 0.0625;
		}
	int AMG88xx::get_Pixel_Temperature(int address){
		int register_address = address;
		int reading[sizeof(buffer)];
		for(uint i=0;i<sizeof(buffer);i++){
			register_address = register_address + i;
			buffer[0] = register_address;
			i2c.compose(buffer,1);
			i2c.consult(buffer,1);
			reading[i] = buffer[0];
			}
		int Pixel_Temperature = ((reading[1] << 8) | reading[0]);
		return Pixel_Temperature * 0.25;
		}
}
