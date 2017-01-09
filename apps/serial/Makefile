#
# Copyright 2016, Data61
# Commonwealth Scientific and Industrial Research Organisation (CSIRO)
# ABN 41 687 119 230.
#
# This software may be distributed and modified according to the term of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(D61_BSD)
#

TARGETS := $(notdir ${SOURCE_DIR}).cdl
ADL := serial.camkes

Driver_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Driver/src/*.c)) 

Pl2303_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Pl2303/src/*.c))

Probe_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Probe/src/*.c))

Driver_LIBS += usbdrivers

ifdef CONFIG_ARCH_X86
Driver_LIBS += pci sel4allocman sel4allocman sel4simple
endif

include ${PWD}/tools/camkes/camkes.mk
