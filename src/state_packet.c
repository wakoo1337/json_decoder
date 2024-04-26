#include <string.h>
#include "contrib/oj/oj.h"
#include "Context.h"
#include "state_source.h"
#include "state_noninteresting.h"

#include "state_packet.h"
void state_packet(ojVal value, struct Context *ctx) {
	if (value->type == OJ_OBJECT) {
		ctx->depth++;
		ctx->stack[ctx->depth] = strcmp(oj_key(value), "_source") ? &state_noninteresting : &state_source;
		for (unsigned long int i=0;i < ctx->items_count;i++) ctx->items[i] = strdup("?");
	} else if (value->type == OJ_ARRAY) {
		ctx->depth++;
		ctx->stack[ctx->depth] = &state_noninteresting;
	}
};
