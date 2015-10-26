obj-m := calc.o
KDIR := /usr/src/linux-headers-3.16.0-4-amd64
PWD := $(shell pwd)
all:
	        $(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	        $(MAKE) -C $(KDIR) M=$(PWD) clean
