#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"
#include "sys/alt_sys_init.h"

void int_to_seg(int nbr);

int time = 0;//Variable pour le temps


static void timer_interrupt(void *Context){
	
	alt_printf("INTERRUPT timer\n");
	if(time < 999){
		int_to_seg(time);
		time = time +1;
		
	}else{
		time = 0;
	}
	// RESET le bit TO de status pour relancer le timer
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0b01);
}


//Fonction qui prend un entier et le decoupe et ecrit sur les registres des 7 segments
void int_to_seg(int nbr){
	int i =0;
	int tab[3] = {0,0,0};

	while (nbr >= 10) {
		tab[i] = nbr % 10;
		nbr = nbr / 10;
		i = i+1;
	}
	tab[i] = nbr;

	IOWR_ALTERA_AVALON_PIO_DATA(SEG1_BASE,tab[0]);
	IOWR_ALTERA_AVALON_PIO_DATA(SEG2_BASE,tab[1]);
	IOWR_ALTERA_AVALON_PIO_DATA(SEG3_BASE,tab[2]);

}



int main(){
	
	
	alt_printf("Dans le main\n");
	//Creation de l'interruption
	if(alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID,TIMER_0_IRQ, timer_interrupt,NULL, NULL) != 0){
		alt_printf("Erreur creation interruption pour le timer\n");
	}
	
	// CHECK LE STATUS
	int status = IORD_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE);
	alt_printf("STATUS = %x\n",status);
	
	// CHECK LE CONTROL
	int control = IORD_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE);
	alt_printf("CONTROL = %x\n",control);
	
	
	while(1){
		
	}
}
