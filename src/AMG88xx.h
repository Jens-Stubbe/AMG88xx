#pragma once
#include "I2C.h"

namespace amg88xx{
	class AMG88xx{
		public:
			AMG88xx();
			void set_Operation_Mode(int value);
			void set_FPS(int value);
			void reset();
			int get_Ambient_Temperature();
			int get_Pixel_Temperature(int address);
		private:
			i2c::I2C i2c;
			char buffer[2];
			const int slave_address = 0x69;
	};
}
