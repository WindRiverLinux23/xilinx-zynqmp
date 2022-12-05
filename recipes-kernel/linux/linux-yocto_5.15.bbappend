LINUX-YOCTO_INC_XILINX-ZYNQMP = ""
LINUX-YOCTO_INC_XILINX-ZYNQMP:xilinx-zynqmp = "linux-yocto-xilinx-zynqmp.inc"
require ${LINUX-YOCTO_INC_XILINX-ZYNQMP}

KBRANCH:xilinx-zynqmp  = "v5.15/standard/sdkv5.15/xlnx-soc"

LINUX_VERSION:xilinx-zynqmp ?= "5.15.x"
