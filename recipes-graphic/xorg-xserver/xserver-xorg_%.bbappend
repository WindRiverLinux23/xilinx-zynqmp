PACKAGECONFIG:remove:xilinx-zynqmp = "${@bb.utils.contains('PNWHITELIST:xilinx', 'libmali-xlnx', ' dri glx xwayland', '', d)}"
