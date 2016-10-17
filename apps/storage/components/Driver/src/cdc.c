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

void cdc_write(uintptr_t dev, int size)
{
	usb_cdc_write((usb_dev_t*)dev, buf, size);
}

int cdc_read(uintptr_t dev, int size)
{
	return usb_cdc_read((usb_dev_t*)dev, buf, size);
}

