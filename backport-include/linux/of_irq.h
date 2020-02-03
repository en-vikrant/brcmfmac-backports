#ifndef __BACKPORT_OF_IRQ_H
#define __BACKPORT_OF_IRQ_H
#include_next <linux/of_irq.h>
#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(3,16,0)
#define of_irq_get_byname LINUX_BACKPORT(of_irq_get_byname)
static inline int of_irq_get_byname(struct device_node *dev, const char *name)
{
	return -1;
}
#endif /* LINUX_VERSION_IS_LESS(3,16,0) */

#if LINUX_VERSION_IS_LESS(3,5,0) && !defined(CONFIG_OF)
#define irq_of_parse_and_map LINUX_BACKPORT(irq_of_parse_and_map)
static inline unsigned int irq_of_parse_and_map(struct device_node *dev,
						int index)
{
	return 0;
}
#endif /* LINUX_VERSION_IS_LESS(3,5,0) */

#if LINUX_VERSION_IS_LESS(3,19,0)
#define of_irq_get irq_of_parse_and_map
#endif

#endif /* __BACKPORT_OF_IRQ_H */
