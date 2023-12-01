#ifndef CHECKSUM_BENCHMARK_PAGE_NEW_H
#define CHECKSUM_BENCHMARK_PAGE_NEW_H

#include <stdint.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0
typedef enum
{
	pgPageSize1 =  1 * 1024,
	pgPageSize2 =  2 * 1024,
	pgPageSize4 =  4 * 1024,
	pgPageSize8 =  8 * 1024,
	pgPageSize16 = 16 * 1024,
	pgPageSize32 = 32 * 1024,
} PgPageSize;


uint16_t
pgPageChecksum(unsigned char *const page, const uint32_t blockNo, const PgPageSize pageSize);

bool
pgPageSizeValid(const PgPageSize pageSize);

void
pgPageSizeCheck(const PgPageSize pageSize);

#endif //CHECKSUM_BENCHMARK_PAGE_NEW_H
