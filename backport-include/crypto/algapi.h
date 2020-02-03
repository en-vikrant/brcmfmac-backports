#ifndef __BP_ALGAPI_H
#define __BP_ALGAPI_H
#include <linux/version.h>
#include_next <crypto/algapi.h>
#if LINUX_VERSION_IS_LESS(4,8,0)
#include <crypto/kpp.h>
#include <crypto/ecdh.h>
#endif

#if LINUX_VERSION_IS_LESS(3,13,0)
#define __crypto_memneq LINUX_BACKPORT(__crypto_memneq)
noinline unsigned long __crypto_memneq(const void *a, const void *b, size_t size);
#define crypto_memneq LINUX_BACKPORT(crypto_memneq)
static inline int crypto_memneq(const void *a, const void *b, size_t size)
{
        return __crypto_memneq(a, b, size) != 0UL ? 1 : 0;
}
#endif

#if LINUX_VERSION_IS_LESS(4,11,0)
#define __crypto_xor LINUX_BACKPORT(__crypto_xor)
void __crypto_xor(u8 *dst, const u8 *src1, const u8 *src2, unsigned int len);
#endif

#if LINUX_VERSION_IS_LESS(4,8,0)
#define crypto_alloc_kpp LINUX_BACKPORT(crypto_alloc_kpp)
struct crypto_kpp *crypto_alloc_kpp(const char *alg_name, u32 type, u32 mask);
#define crypto_ecdh_key_len LINUX_BACKPORT(crypto_ecdh_key_len)
unsigned int crypto_ecdh_key_len(const struct ecdh *params);
#endif

#if LINUX_VERSION_IS_LESS(4,1,0)
#define CRYPTO_ALG_INTERNAL		0x00002000
#endif

#endif /* __BP_ALGAPI_H */
