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
#include <stdio.h>
#include <stdlib.h>

int usb_cdc_read(void *udev, void *buf, int size)
{
	return cdc_read(NULL, size);
}

void usb_cdc_write(void *udev, void *buf, int size)
{
	cdc_write(NULL, size);
}

int run()
{
	printf("Starting the driver\n");
	printf("-------------------\n");

	printf("After the driver\n");
	return 0;
}
