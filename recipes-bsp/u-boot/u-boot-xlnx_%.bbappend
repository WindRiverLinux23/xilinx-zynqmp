FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:xilinx-zynqmp = "${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'file://0001-u-boot-xlnx-force-to-build-dtb-file.patch', '', d)}"
