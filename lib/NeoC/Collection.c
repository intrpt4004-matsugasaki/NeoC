#include "NeoC/Collection.h"

static int32_t GetLength(self *col) {
	return act(Collection_t, col)->_Length;
}

static bool IsEmpty(self *col) {
	return act(Collection_t, col)->_Length == 0;
}

static void Init(Collection_t *col) {
	col->_Size 			= 0;
	col->_Length		= 0;
	mtx_init(&col->_Mtx, mtx_plain);

	col->GetLength		= GetLength;
	col->IsEmpty		= IsEmpty;
}

static void Delete(Collection_t *col) {
	_Memory.Free(col);
}

_Collection Collection = {
	.Init			= Init,
	.Delete			= Delete,

	.GetLength		= GetLength,

	.IsEmpty		= IsEmpty,
};
