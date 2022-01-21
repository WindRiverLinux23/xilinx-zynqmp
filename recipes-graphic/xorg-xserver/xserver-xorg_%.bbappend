PACKAGECONFIG:remove:xilinx-zynqmp = "${@bb.utils.contains('PNWHITELIST:xilinx', 'libmali-xlnx', ' dri glx xwayland', '', d)}"
DEPENDS:append:xilinx-zynqmp = "${@bb.utils.contains('PACKAGECONFIG', 'dri3', ' libxshmfence', '', d)}"
