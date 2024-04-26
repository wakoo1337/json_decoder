#include <stdio.h>
#include <stdlib.h>
#include "contrib/oj/oj.h"
#include "Context.h"
#include "state_packet.h"

#include "json_pop.h"
void json_pop(void *user) {
	struct Context *ctx = (struct Context *) user;
	if (ctx->stack[ctx->depth] == &state_packet) {
		for (unsigned int i=0;i<ctx->items_count;i++) {
			fputs(ctx->items[i], stdout);
			if (i < ctx->items_count-1) fputc(',', stdout);
			free(ctx->items[i]);
		};
		fputc('\n', stdout);
	};
	ctx->depth = ctx->depth ? ctx->depth-1 : 0;
};
