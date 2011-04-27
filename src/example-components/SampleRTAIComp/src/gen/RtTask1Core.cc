//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.2
// The SmartSoft Toolchain has been developed by:
//  
// ZAFH Servicerobotic Ulm
// Christian Schlegel (schlegel@hs-ulm.de)
// University of Applied Sciences
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// smart-robotics.sourceforge.net
// 
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------

#include "RtTask1Core.hh"
#include "SampleRTAIComp.hh"

static void task(void* obj)
{
	reinterpret_cast<RtTask1Core*> (obj)->myTask();
}

void RtTask1Core::open()
{
	// rt_thread_create,(void *fun, void *args, int stack_size)
	thread = rt_thread_create(reinterpret_cast<void*> (task),
			reinterpret_cast<void*> (this), 0); // TODO old stack size 10000 ???
}

void RtTask1Core::close()
{
	rt_make_soft_real_time(); //???
	rt_task_delete(handler);
}

void RtTask1Core::smart_task_wait_period()
{
	rt_task_wait_period();
}

void RtTask1Core::myTask()
{
	usleep(100000); // TODO
	rt_allow_nonroot_hrt();
	mlockall(MCL_CURRENT | MCL_FUTURE);

	// rt_task_init (int name, int priority, int stack_size, int max_msg_size)
	// highest priotity = 0
	if (!(handler = rt_task_init(rt_get_name(0), 1, 0, 0)))
	{
		printf("CANNOT INIT HANDLER RTAI TASK > RtTask1 <\n");
		exit(1);
	}

	RTIME period = (long) (0.5 * 1000* 1000* 1000 ) ;
	rt_make_hard_real_time();
	rt_task_make_periodic(handler, rt_get_time(), nano2count(period));

	// call to svc
	svc();
}
