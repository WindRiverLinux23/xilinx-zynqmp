FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:xilinx-zynqmp = " file://0001-u-boot-xlnx-enable-u-boot-configure-CONFIG_OF_SEPARA.patch \
"

UBOOT_VERSION:xilinx-zynqmp = "v2019.02"
UBRANCH:xilinx-zynqmp = "master"
SRCREV:xilinx-zynqmp = "dc61275b1d505f6a236de1c5b0f35485914d2bcc"
UBOOT_INITIAL_ENV:xilinx-zynqmp = ""
