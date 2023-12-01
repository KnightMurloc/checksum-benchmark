#ifndef CHECKSUM_BENCHMARK_PAGE_H
#define CHECKSUM_BENCHMARK_PAGE_H
#include <stdint.h>
#include "static.vendor.h"

uint16 pg_checksum_page(char *page, BlockNumber blkno);
#endif //CHECKSUM_BENCHMARK_PAGE_H
