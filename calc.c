#include <stdio.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("Dual BSD/GPL");


ssize_t read_first (struct file * f, char __user * u, size_t s, loff_t * l)
{
	printf(f, "ha");
	return 2;	
}

ssize_t write_first (struct file * f, const char __user * u, size_t s, loff_t * l)
{
	return 1;	
}

int release_first (struct inode * n, struct file * f)
{
	return 0;
}

int open_first (struct inode * n, struct file * f)
{
	return 0;
}

const struct file_operations fops_first = {
	.owner   = THIS_MODULE,
	.llseek  = no_llseek,
	.read    = read_first,
	.write   = write_first,
	.open    = open_first,
	.release = release_first,
};
;

int dev_first;


/*unregister_chrdev(major,"mydriver");*/

/*/proc/devices   - список драйверов устройств, их MAJOR number*/
static int hello_init(void)
{
	
	dev_first = register_chrdev(0, "first", &fops_first);
	return 0;
}

static void hello_exit(void)
{
	unregister_chrdev(dev_first, "first");
}

module_init(hello_init);
module_exit(hello_exit);
