camkes-usb-tests
===============

Tests for the USB driver in CAmkES environment.

This repository also contains the repo manifest for the tests.

To fetch do:

    mkdir camkes-usb-tests
    cd camkes-usb-tests
    repo init -u https://github.com/smaccm/camkes-usb-tests.git
    repo sync

To compile do:
(Same kernel hack(changes to acpi.c) needs to be applied too, if the gvrbot does
 not have the proper BIOS setting)

    cd camkes-usb-tests
    make ia32_gvrbot_defconfig
    make

