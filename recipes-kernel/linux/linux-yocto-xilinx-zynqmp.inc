#
# Copyright (C) 2019 Wind River Systems, Inc.
#


COMPATIBLE_MACHINE:xilinx-zynqmp = "xilinx-zynqmp"

TARGET_SUPPORTED_KTYPES:xilinx-zynqmp = "standard preempt-rt"

FILESEXTRAPATHS:prepend:xilinx-zynqmp := "${THISDIR}/files:"

SRC_URI:append:xilinx-zynqmp = " \
    file://0001-arch-arm64-dts-add-dts-file-for-CANFD-feature-on-xil.patch \
"

KERNEL_VERSION_SANITY_SKIP = "1"
SRCREV_machine:xilinx-zynqmp ?= "${AUTOREV}"
SRCREV_meta:xilinx-zynqmp ?= "${AUTOREV}"
