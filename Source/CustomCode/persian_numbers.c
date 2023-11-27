#include "persian_numbers.h"

const char *persian_numbers[10] = { "۰" , "۱" , "۲" , "۳" , "۴" , "۵" , "۶" , "۷" , "۸" , "۹"};

void convert_persain_number(int number, char* str_output) {
	uint8_t len = 0;
	uint8_t digit;
	char str_temp[32];
	uint8_t signed_data = 0;
	str_temp[0] = 0; str_output[0] = 0;
	if (number < 0) {
		signed_data = 1;
		number *= -1;
	}
	 do{
		 digit = number % 10;
#ifdef _MSC_VER
		 wcscpy(str_temp, persian_numbers[digit]);
#elif defined __GNUC__
		 strcpy(str_temp, persian_numbers[digit]);
#endif
		 strcat(str_temp, str_output);
		 strcpy(str_output, str_temp);
		 number /= 10;
	}while (number != 0);
	if (signed_data) {
		strcpy(str_temp, "-");
		strcat(str_temp, str_output);
		strcpy(str_output, str_temp);
	}
}
