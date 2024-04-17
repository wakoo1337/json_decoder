#include "contrib/oj/oj.h"
#include "Context.h"

#include "state_noninteresting.h"
void state_noninteresting(ojVal value, struct Context *ctx) {
	if ((value->type == OJ_OBJECT) || (value->type == OJ_ARRAY)) {
		ctx->depth++;
		ctx->stack[ctx->depth] = &state_noninteresting;
	}
};
