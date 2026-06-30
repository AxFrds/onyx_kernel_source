/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _LINUX_MCA_COMMON_MCA_SYSFS_H
#define _LINUX_MCA_COMMON_MCA_SYSFS_H

#include <linux/device.h>
#include <linux/string.h>
#include <linux/sysfs.h>

#ifndef SYSFS_DEV_0
#define SYSFS_DEV_0 0
#endif

#ifndef SYSFS_DEV_1
#define SYSFS_DEV_1 1
#endif

#ifndef SYSFS_DEV_2
#define SYSFS_DEV_2 2
#endif

#ifndef SYSFS_DEV_3
#define SYSFS_DEV_3 3
#endif

struct mca_sysfs_attr_info {
	int sysfs_attr_name;
	struct device_attribute attr;
};

#define mca_sysfs_attr_ro(_prefix, _mode, _prop, _attr_name) \
	{ \
		.sysfs_attr_name = _prop, \
		.attr = __ATTR(_attr_name, _mode, _prefix##_show, NULL), \
	}

static inline struct mca_sysfs_attr_info *
mca_sysfs_lookup_attr(const char *name, struct mca_sysfs_attr_info *tbl, int size)
{
	int i;

	for (i = 0; i < size; i++) {
		if (tbl[i].attr.attr.name && !strcmp(name, tbl[i].attr.attr.name))
			return &tbl[i];
	}

	return NULL;
}

static inline int mca_sysfs_create_files(int dev, struct mca_sysfs_attr_info *tbl, int size)
{
	return 0;
}

#endif
