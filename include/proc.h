


typedef struct s_stackframe {	
	t_32	gs;		/* ┓						│			*/
	t_32	fs;		/* ┃						│			*/
	t_32	es;		/* ┃						│			*/
	t_32	ds;		/* ┃						│			*/
	t_32	edi;		/* ┃						│			*/
	t_32	esi;		/* ┣ pushed by save()				│			*/
	t_32	ebp;		/* ┃						│			*/
	t_32	kernel_esp;	/* <- 'popad' will ignore it			│			*/
	t_32	ebx;		/* ┃						↑栈从高地址往低地址增长*/		
	t_32	edx;		/* ┃						│			*/
	t_32	ecx;		/* ┃						│			*/
	t_32	eax;		/* ┛						│			*/
	t_32	retaddr;	/* return address for assembly code save()	│			*/
	t_32	eip;		/*  ┓						│			*/
	t_32	cs;		/*  ┃						│			*/
	t_32	eflags;		/*  ┣ these are pushed by CPU during interrupt	│			*/
	t_32	esp;		/*  ┃						│			*/
	t_32	ss;		/*  ┛						┷High			*/
}STACK_FRAME;


typedef struct s_proc {
	STACK_FRAME			regs;			

	t_16				ldt_sel;		
	DESCRIPTOR			ldts[LDT_SIZE];		
								
	int				ticks;		
	int				priority;
	t_32				pid;			
	char				name[16];		
}PROCESS;


typedef struct s_task {
	t_pf_task	initial_eip;
	int		stacksize;
	char		name[32];
}TASK;


#define NR_TASKS		3


#define STACK_SIZE_TESTA	0x8000
#define STACK_SIZE_TESTB	0x8000
#define STACK_SIZE_TESTC	0x8000

#define STACK_SIZE_TOTAL	(STACK_SIZE_TESTA + \
				STACK_SIZE_TESTB + \
				STACK_SIZE_TESTC)

