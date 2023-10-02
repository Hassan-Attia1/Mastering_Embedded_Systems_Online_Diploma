/* Hassan Attia*/

#include <stdint.h>


void  reset_handler  ();
void Default_Handler ();
void  NMI            () __attribute__((weak, alias ("Default_Handler")));;
void  Hard_Fault     () __attribute__((weak, alias("Default_Handler")));;
void  MemManage      () __attribute__((weak, alias("Default_Handler")));;
void  BusFault       () __attribute__((weak, alias("Default_Handler")));;
void  Usage_Fault    () __attribute__((weak, alias("Default_Handler")));;
void  SV_Call        () __attribute__((weak, alias("Default_Handler")));;



//using extern class for functions and symbols to make linker script links without errors 
extern int main(void);
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
 


unsigned long stack_top [256] = {0}; //creating .bss section to initilize the stack 


	void (* g_vectors_arr_of_ptrs_to_fn[])() __attribute__((section(".vectors"))) = {
		
	(void (*)())((unsigned long)stack_top + sizeof(stack_top)),
	
	&reset_handler,
	&NMI,
	&Hard_Fault,
	&MemManage,
	&BusFault,
	&Usage_Fault,
	&SV_Call

		
	};



void  reset_handler  (){
	int j;
	//copying from flash to ram
	unsigned int data_size  = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* p_src = (unsigned char*)&_E_text;
	unsigned char* p_dst = (unsigned char*)&_S_data;
	
	for(j = 0 ; j<data_size; j++){
		
		*((unsigned char*)p_dst++) = *((unsigned char*)p_src++); 
		
	}
	
	//Initilize .bss with zeros in ram s 
	unsigned int bss_size  = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	
	p_dst = (unsigned char*)&_S_bss;
	
		for(j = 0 ; j<bss_size; j++){
		
		*((unsigned char*)p_dst++) = (unsigned char)0; 
		
	}
	//Jumping to the main()
	
	
	main();
	
}



	void Default_Handler (){
	reset_handler();
	}
