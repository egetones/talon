// SPDX-License-Identifier: GPL-2.0
/*
 * talon_core.c — Talon EDR çekirdek modülü, Hafta 1 iskeleti
 *
 * Bu aşamada:
 *   - modül yükleme/kaldırma (insmod/rmmod)
 *   - /proc/talon üzerinden "alive" kontrolü
 * Hafta 1'in ikinci adımında buraya kallsyms tabanlı ham modül
 * listesi okuma (module_watch) eklenecek.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/seq_file.h>

#define TALON_PROC_NAME "talon"

static struct proc_dir_entry *talon_proc_entry;

static int talon_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "talon: alive\n");
	seq_printf(m, "version: 0.1-week1\n");
	return 0;
}

static int talon_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, talon_proc_show, NULL);
}

static const struct proc_ops talon_proc_fops = {
	.proc_open    = talon_proc_open,
	.proc_read    = seq_read,
	.proc_lseek   = seq_lseek,
	.proc_release = single_release,
};

static int __init talon_init(void)
{
	talon_proc_entry = proc_create(TALON_PROC_NAME, 0444, NULL, &talon_proc_fops);
	if (!talon_proc_entry) {
		pr_err("talon: /proc/%s olusturulamadi\n", TALON_PROC_NAME);
		return -ENOMEM;
	}

	pr_info("talon: modul yuklendi, /proc/%s hazir\n", TALON_PROC_NAME);
	return 0;
}

static void __exit talon_exit(void)
{
	proc_remove(talon_proc_entry);
	pr_info("talon: modul kaldirildi\n");
}

module_init(talon_init);
module_exit(talon_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("egetones");
MODULE_DESCRIPTION("Talon EDR - core module (week 1 skeleton)");
MODULE_VERSION("0.1");
