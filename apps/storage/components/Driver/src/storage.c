/*
 * Copyright 2016, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the term of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(D61_BSD)
 */

#include <camkes.h>
#include <usb/usb.h>
#include <usb/drivers/storage.h>

#define STORAGE_CLASS_CODE  0x8

extern usb_t usb;

uintptr_t disk_find(int vid, int did)
{
	int cnt = 1;
	usb_dev_t usbdev = NULL;

	do {
		usbdev = usb_get_device(&usb, cnt);
		if (usbdev &&
			usbdev->vend_id == vid && usbdev->prod_id == did) {
			break;
		}
		cnt++;
	} while (usbdev);

	return (uintptr_t)usbdev;
}

int disk_connect(uintptr_t dev)
{
	return usb_storage_bind((usb_dev_t)dev);
}

int disk_init(uintptr_t dev)
{
	return usb_storage_init_disk((usb_dev_t)dev);
}

int disk_get_capacity(uintptr_t dev)
{
	return usb_storage_get_capacity((usb_dev_t)dev);
}

