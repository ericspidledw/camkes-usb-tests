/*
 * Copyright 2015, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>

#include <usb/usb.h>

static void usb_irq_handler(void *arg)
{
	usb_t *priv = (usb_t*)arg;

	usb_handle_irq(priv);

	irq_reg_callback(usb_irq_handler, priv);
}

int run() {
    int err;
    usb_t *usb;
    usb_dev_t usb_storage;
    ps_io_ops_t io_ops;

    printf("Starting the driver\n");
    printf("-------------------\n");

    camkes_io_ops(&io_ops);
    usb = malloc(sizeof(usb_t));

    err = usb_init(USB_HOST2, &io_ops, usb);
    assert(err);

    irq_reg_callback(usb_irq_handler, usb);

    while (1) {
	    usb_storage = usb_get_device(usb, 5);
	    if (usb_storage) {
		    break;
	    }
    }

    usb_lsusb(usb, 1);
    usb_storage_bind(usb_storage, NULL);

    printf("After the driver\n");
    return 0;
}
