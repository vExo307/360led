#include "SMC\\smc.h"

int main(){
	smc s;
    s.SetLEDS(GREEN,OFF,OFF,OFF);
	s.SetLEDS(GREEN,GREEN,OFF,OFF);
	s.SetLEDS(GREEN,GREEN,GREEN,OFF);
	s.SetLEDS(GREEN,GREEN,GREEN,GREEN);
	return 1;
}