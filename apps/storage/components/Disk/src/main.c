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

#define VID  0x1908//0x0951  //Kingston
#define DID  0x1319//0x1605  //DataTravelerMini
int run()
{
	uintptr_t disk = NULL;
	uint32_t capacity = 0;

	printf("Starting the Disk\n");
	printf("-------------------\n");

	/* Find the device */
	while (!disk) {
		disk = disk_find(VID, DID);
	}
	printf("Found USB disk\n");

	disk_connect(disk);

	disk_init(disk);

	capacity = disk_get_capacity(disk);

	printf("Disk capacity: %u\n", capacity);
	
	printf("Well done, Disk!\n");
	return 0;
}
