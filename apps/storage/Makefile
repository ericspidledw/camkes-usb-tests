#
# Copyright 2015, NICTA
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(NICTA_BSD)
#

TARGETS := $(notdir ${SOURCE_DIR}).cdl
ADL := storage.camkes

Driver_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Driver/src/*.c)) 

Driver_LIBS += usbdrivers

ifdef CONFIG_ARCH_X86
Driver_LIBS += pci
endif

include ${PWD}/tools/camkes/camkes.mk
