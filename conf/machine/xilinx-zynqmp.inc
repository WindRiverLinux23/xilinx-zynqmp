#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "cortexa53"
require conf/machine/include/arm/armv8a/tune-cortexa53.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat keyboard network"

KERNEL_IMAGETYPE = "${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'fitImage', 'Image', d)}"
KERNEL_DEVICETREE:xilinx-zynqmp = "xilinx/zynqmp-zcu102-rev1.0.dtb xilinx/zynqmp-zcu102-rev1.0-canfd.dtb"
KERNEL_EXTRA_ARGS:append:xilinx-zynqmp = " DTC_FLAGS='-@'"

SERIAL_CONSOLE = "115200 ttyPS0"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"
PREFERRED_VERSION_linux-yocto ?= "5.15%"
PREFERRED_VERSION_linux-yocto-rt ?= "5.15%"

MACHINE_EXTRA_RRECOMMENDS = " kernel-modules kernel-devicetree"
IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"

# wic support
IMAGE_INSTALL:append = " ${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'kernel-devicetree kernel-image-fitimage', 'kernel-devicetree kernel-image-image', d)}"
WKS_FILE ?= "zynqmp-sdimage.wks"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"
IMAGE_BOOT_FILES ?= "${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'fitImage', 'Image zynqmp-zcu102-rev1.0.dtb', d)}"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE:virtclass-multilib-lib32 ?= "armv7athf-neon"

# secure boot related configurations
UBOOT_SIGN_ENABLE = "${@bb.utils.contains("MACHINE_FEATURES", "secure-boot", "1", "", d)}"
UBOOT_SIGN_KEYDIR = "${@bb.utils.contains("FIT_SIGN_ALG", "rsa4096", "${LAYER_PATH_wr-xilinx-zynqmp}/zynqmp_keys/fitImage-rsa4096-keys", "${LAYER_PATH_wr-xilinx-zynqmp}/zynqmp_keys/fitImage-rsa2048-keys", d)}"
UBOOT_MKIMAGE_DTCOPTS = "-I dts -O dtb -p 2000"
UBOOT_SIGN_KEYNAME = "dev"
# Key used to sign kernel and dtb parts in fit image
UBOOT_SIGN_IMG_KEYNAME = "dev_individual"
FIT_SIGN_INDIVIDUAL  = "1"

UBOOT_ENTRYPOINT = "0x80000"
UBOOT_LOADADDRESS = "0x80000"

UBOOT_ELF="u-boot.elf"
UBOOT_ELF_SUFFIX ?= "elf"

UBOOT_MACHINE = "xilinx_zynqmp_zcu102_rev1_0_defconfig"
SPL_BINARY ?= "spl/boot.bin"
PREFERRED_PROVIDER_u-boot = "u-boot-xlnx"
UBOOT_SUFFIX = "img"
NON_MULTILIB_RECIPES:append = " u-boot-xlnx"

KERNEL_CLASSES  = " kernel-fitimage "

# Xilinx secure boot feature supports rsa2048 and rsa4096 key type.
# Set FIT_SIGN_ALG as the expected value. The default one is rsa2048.
FIT_SIGN_ALG = "rsa2048"
#FIT_SIGN_ALG = "rsa4096"

# Xilinx secure boot feature supports sha1 and sha256 digest.
# Set KERNEL_CSUM_TYPE as the expected value. The default one is sha1.
FIT_HASH_ALG = "sha256"
#FIT_HASH_ALG = "sha1"

INSECURE_KEY_MSG = "\
WARNING: The insecure sample keys are used for secure Boot.\
Please ensure that you are aware of what your risk to use these keys in your own product."

# Warn the user if sample key is used
BANNER[xilinx-zynqmp_default] = "${INSECURE_KEY_MSG}"

XSERVER:append = " xf86-video-armsoc"
OSTREE_BOOTLOADER_INCLUDE ?= ""
OSTREE_SD_UBOOT_WIC1 ?= ""
OSTREE_SD_BOOT_ALIGN ?= "4096"
OSTREE_FDISK_BLM ?= "8192"
OSTREE_FDISK_FSZ ?= "132"
OSTREE_KERNEL ?= "Image"
OSTREE_UBOOT_CMD ?= "booti"
OSTREE_WKS_EFI_SIZE ?= "--size=64M"
INSTAB ?= "1"
DEFAULT_DTB ?= "zynqmp-zcu102-rev1.0.dtb"
OSTREE_NETINST_DEV ?= "/dev/mmcblk0,/dev/sda,/dev/vda"
OSTREE_NETINST_ARGS ?= "${OSTREE_CONSOLE} bl=ufsd rdinit=/install instdev=${OSTREE_NETINST_DEV} instname=wrlinux instbr=\$BRANCH insturl=\$URL instab=${OSTREE_USE_AB} instsf=1 instdate=BUILD_DATE"
OSTREE_COPY_IMAGE_BOOT_FILES = "1"
INITRAMFS_IMAGE ??= ""
IMAGE_BOOT_FILES:append = " ${@bb.utils.contains('DISTRO_FEATURES', 'ostree', 'boot.scr', '', d)} ${@bb.utils.contains('DISTRO_FEATURES', 'ostree', '${INITRAMFS_IMAGE}-${MACHINE}.${INITRAMFS_FSTYPES};initramfs', '', d)}"
MACHINEOVERRIDES:prepend:xilinx-zynqmp = "mali400:zynqmp:zynqmp-eg:"

OSTREE_BOOTSCR_PRECMD ?= "\
setenv no_menu yes; \
"
