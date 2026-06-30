/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _LINUX_MCA_COMMON_MCA_LOG_H
#define _LINUX_MCA_COMMON_MCA_LOG_H

#include <linux/kernel.h>

#ifndef MCA_LOG_TAG
#define MCA_LOG_TAG "mca"
#endif

#define mca_log_err(fmt, ...)  pr_err("[%s] " fmt, MCA_LOG_TAG, ##__VA_ARGS__)
#define mca_log_info(fmt, ...) pr_info("[%s] " fmt, MCA_LOG_TAG, ##__VA_ARGS__)
#define mca_log_dbg(fmt, ...)  pr_debug("[%s] " fmt, MCA_LOG_TAG, ##__VA_ARGS__)

#endif
