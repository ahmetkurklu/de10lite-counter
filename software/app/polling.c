#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"


int main(){
	
	int i =0;
	int j = 0;
	int k = 0;
	while(1){
		for(i=0;i<10;i++){
			IOWR_ALTERA_AVALON_PIO_DATA(SEG3_BASE,i);
			for(j=0;j<10;j++){
				IOWR_ALTERA_AVALON_PIO_DATA(SEG2_BASE,j);
				for(k=0;k<10;k++){
					IOWR_ALTERA_AVALON_PIO_DATA(SEG1_BASE,k);
					usleep(400000);
				}
			}
		}
	}
}

