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
#include <camkes/io.h>
#include <stdio.h>
#include <stdlib.h>

#include <usb/usb.h>

static void *mutex_init(void)
{
	return (void *)1234;
}

static int mutex_lock(void *mutex)
{
	m_lock();
	return 0;
}

static int mutex_unlock(void *mutex)
{
	m_unlock();
	return 0;
}

static int mutex_destroy(void *mutex)
{
	return 0;
}

static void usb_irq_handler(void *arg)
{
	usb_t *priv = (usb_t *) arg;

	usb_handle_irq(priv);

	irq_reg_callback(usb_irq_handler, priv);
}

usb_t usb;
ps_io_ops_t io_ops;
mutex_ops_t mutex_ops;

void pre_init(void)
{
	int err;

	mutex_ops.mutex_init = mutex_init;
	mutex_ops.mutex_lock = mutex_lock;
	mutex_ops.mutex_unlock = mutex_unlock;
	mutex_ops.mutex_destroy = mutex_destroy;

	camkes_io_ops(&io_ops);

	err = usb_init(USB_HOST_DEFAULT, &io_ops, &mutex_ops, &usb);
	assert(!err);

	irq_reg_callback(usb_irq_handler, &usb);
}

