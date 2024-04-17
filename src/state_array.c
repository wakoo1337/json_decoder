#include <string.h>
#include <stdlib.h>
#include "contrib/oj/oj.h"
#include "Context.h"
#include "state_packet.h"
#include "state_noninteresting.h"

#include "state_array.h"
void state_array(ojVal value, struct Context *ctx) {
	if (value->type == OJ_OBJECT) {
		memset(ctx->items, 0, ctx->items_count * sizeof(char *));
		ctx->depth++;
		ctx->stack[ctx->depth] = &state_packet;
	} else if (value->type == OJ_ARRAY) {
		ctx->depth++;
		ctx->stack[ctx->depth] = &state_noninteresting;
	}
};
