#ifndef __DEVICE_H_
#define __DEVICE_H_

/* Polymorphous device implementation */

#include <stdint.h>
#include <definitions.h>

struct _device_;

/* TODO:
 * different procedures like __ps2_getch(), __ps2_kbhit() than one common __ps2_procedure()
 */
typedef ulong_t(*dev_mode__procedure)(int signal, void* data, size_t size, struct _device_* d_ptr);

/* Enum with device indexes */
enum _dev_mode_device_ {
    __dev_keyboard,
    __dev_mouse
} dev_mode_device;

/* Device structure.
 * Has:
 * 	device_s = device index
 * 	proc = pointer to a device's procedure function
 */
typedef struct _device_ {
    
    int device_s;
    dev_mode__procedure proc;

} _packed_ device;

/* Pragmas for actions with devices */

/* Second method:
 * Replace pragmas except *_tb and devCast with inline functions */

/* Execute device's procedure. */
#define devCall(signal, data, size, dev) \
    dev->proc(signal, data, size, dev)

/* Cast any object inherited from device to device. */
#define devCast(dev) ((device*)dev)

/* Compare procedures in two devices */
#define procCmp(dev0, dev1) \
    dev0->proc == dev1->proc

/* Set procedure for 'dev' to 'proc' */
#define setProc(dev, proc) \
    dev->proc = proc

/* Check if device's index is equal 'ind' */
#define checkIndex(dev, ind) \
    dev->device_s == ind

/* Init a device with dv - device, tp - device index, pr - procedure */
#define init_device(dv,tp,pr) \
    (dv->proc = dm, dv->device_s = tp)

/* Define device as one entry table
 * 	dev 	 - device name
 * 	devtype  - device type (eg. _dev_keyboard_)
 *	devindex - device index (eg. __dev_keyboard)
 *	devproc  - device procedure
 */
#define define_device_tb(dev,devtype,devindex,devproc) \
	devtype dev[1] = { { { { devindex, devproc } } } }

/* Extern device as one entry table
 * 	dev	- device name
 * 	devtype - device type
 */
#define extern_device_tb(dev, devtype) \
	extern devtype dev[1];

#endif
