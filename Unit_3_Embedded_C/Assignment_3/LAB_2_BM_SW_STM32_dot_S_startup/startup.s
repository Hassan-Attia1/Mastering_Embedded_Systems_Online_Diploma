/*Hassan Attia*/









.section .vectors

.word 0x20001000
.word _reset
.word _vector_handler  /*NMI*/
.word _vector_handler  /*Hard_Fault*/
.word _vector_handler  /*MemManage */
.word _vector_handler  /*Bus_Fault */
.word _vector_handler  /*Usage_Fault*/
.word _vector_handler  /*Reserved */
.word _vector_handler  /*SV_Call */
.word _vector_handler  /*Debug_Monitor*/
.word _vector_handler  /*Reserved*/
.word _vector_handler  /*PendSv */
.word _vector_handler  /*SysTick*/



.thumb_func

.section .text
_reset:
	bl main
	b .
_vector_handler:
	b _reset