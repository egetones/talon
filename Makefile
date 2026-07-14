obj-m += talon_core.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

load:
	sudo insmod talon_core.ko

unload:
	sudo rmmod talon_core

reload: unload load

check:
	cat /proc/talon
	dmesg | tail -n 10
