#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char* argv[]){
	if (argc < 2){
		fprintf(stdout, "Usage %s number.\nVersion: %d.%d\n", 
			argv[0],
			Tutorial_VERSION_MAJOR,
			Tutorial_VERSION_MINOR
			);
		return 1;
	}

	double input_value = atof(argv[1]);
	#ifdef USE_MYMATH
	double output_value = mysqrt(input_value);
	#else
	double output_value = sqrt(input_value);
	#endif
	fprintf(stdout, "The square of %g is %g\n", 
		input_value, output_value);
}