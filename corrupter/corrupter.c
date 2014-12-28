#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

/* Very hefty SLAB allocation, 10 MB.  This is to make it panic faster, increasing the chance of
 * finding the corruption. */
#define SLABSIZE 10000000

static int init_corrupter(void);
static void exit_corrupter(void);
static int use_after_free(void);

static int use_after_free(){
	/* Allocate slab object */
	int *corrupt_cache
	
	corrupt_cache = kmem_cache_create("slab_to_be_corrupted", SLABSIZE, 0, 0, NULL);

	kmem_cache_free(
}

static int init_corrupter(){
	printk("Loading memory corrupter.\nYOUR SYSTEM IS NOW NOW CAPABLE OF OVERWRITING SLAB IN A USE-AFTER-FREE SCENARIO.\n\
		This WILL cause data corruption!  Kernel panics and possible permanent corruption of data are likely!\n");
	use_after_free();
	return 0;
}

static void exit_corrupter(){
	printk("Unloading memory corrupter.\n");
}

module_init(init_corrupter);
module_exit(exit_corrupter);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Robb Manes <robb.manes@gmail.com");
MODULE_DESCRIPTION("Memory corrupter module, used to emulate a random use-after-free scenario.  USE AT YOUR OWN RISK.");
