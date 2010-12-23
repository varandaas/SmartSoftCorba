//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.8.0
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
// This file is generated once. Modify this file to your needs.
// If you want the toolchain to re-generate this file, please
// delete it before running the code generator.
//--------------------------------------------------------------------------

#ifndef _IMAGETASK_HH
#define _IMAGETASK_HH

#include "gen/ImageTaskCore.hh"

#include <CommKinectObjects/commKinectImage.hh>
#include <CommKinectObjects/commMutableKinectImage.hh>
#include <CommKinectObjects/commResizeableKinectImage.hh>
#include <CommKinectObjects/commKinectParameter.hh>

#include <commPose3d.hh>
#include <commBaseState.hh>

#include "KinectWrapper.hh"

class ImageTask: public ImageTaskCore {

public:
	ImageTask();

	virtual ~ImageTask();

	void startCapturing();
	void stopCapturing();
	int svc();

private:
	/**
	 * Internal class which is responsible for deleting the invalid images.
	 */
	class ImageCleanupThread: public CHS::SmartTask {
	public:
		ImageCleanupThread();

		int svc();

		/**
		 * This method enqueues the image which should be deleted into a queue
		 * for asynchronous deletion.
		 */
		inline void remove_reference_to(CommKinectObjects::CommKinectImage *image) {
			if (image)
				_enqueue(image);
		}
		/**
		 * This method can be used to stop the CleanupThread
		 */
		inline void stopThread() {
			_enqueue(0);
		}

		virtual ~ImageCleanupThread();
	private:
		std::queue<CommKinectObjects::CommKinectImage*> _queue;
		CHS::SmartMutex _queue_mutex;
		CHS::SmartSemaphore _queue_sem;

		void _enqueue(CommKinectObjects::CommKinectImage* image);
	};

	ImageCleanupThread* _cleanupThread;

	unsigned int _ring_buffer_index;
	std::vector<CommKinectObjects::CommMutableKinectImage*> _ring_buffer;

	KinectWrapper* device;
	CHS::SmartMutex kinectMutex;

};

#endif
