FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SECURE_BOOT_PATCHES:xilinx-zynqmp = " \
    file://0001-u-boot-xlnx-force-to-build-dtb-file.patch \
    file://0001-arm64-zynqmp-enable-zcu102-rev1.0-board-by-default-f.patch \
"

SRC_URI:append:xilinx-zynqmp = " ${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', '${SECURE_BOOT_PATCHES}', '', d)}"
