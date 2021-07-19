#include "NeoC/Memory.h"

static void *_Inspect(void *ptr) {
	if (ptr == NULL) _Error.Panic(u8"\e[36m", u8"Memory System");
	return ptr;
}

static void *Allocate(const size_t size) {
	return _Inspect(malloc(size));;
}

static void *CountedAllocate(const size_t n, const size_t size) {
	return _Inspect(calloc(n, size));
}

static void *SharedAllocate(const size_t size) {
	return _Inspect(
		mmap(
			NULL,
			size,
			PROT_READ | PROT_WRITE,
			MAP_SHARED | MAP_ANONYMOUS,
			-1, 0
		)
	);
}

static void *ReAllocate(void *ptr, const size_t size) {
	return _Inspect(realloc(ptr, size));
}

static void Free(void *ptr) {
	free(ptr);
}

__Memory _Memory = {
	.Allocate					= Allocate,
	.CountedAllocate			= CountedAllocate,
	.SharedAllocate				= SharedAllocate,
	.ReAllocate					= ReAllocate,
	.Free						= Free,
};
