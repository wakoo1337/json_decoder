#include "contrib/oj/oj.h"
#include "Context.h"
#include "state_noninteresting.h"
#include "state_array.h"

#include "state_start.h"
void state_start(ojVal value, struct Context *ctx) {
	if (value->type == OJ_ARRAY) {
		ctx->depth++;
		ctx->stack[ctx->depth] = &state_array;
	} else if (value->type == OJ_OBJECT) {
		ctx->depth++;
		ctx->stack[ctx->depth] = &state_noninteresting;
	}
};
