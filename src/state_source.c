#include <string.h>
#include "contrib/oj/oj.h"
#include "Context.h"
#include "state_layers.h"
#include "state_noninteresting.h"

#include "state_source.h"
void state_source(ojVal value, struct Context *ctx) {
	if (value->type == OJ_OBJECT) {
		ctx->depth++;
		ctx->stack[ctx->depth] = strcmp(oj_key(value), "layers") ? &state_noninteresting : &state_layers;
	} else if (value->type == OJ_ARRAY) {
		ctx->depth++;
		ctx->stack[ctx->depth] = &state_noninteresting;
	}
};
