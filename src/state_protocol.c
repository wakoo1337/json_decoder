#include <stdlib.h>
#include <string.h>
#include "contrib/oj/oj.h"
#include "contrib/avl.h"
#include "Context.h"
#include "state_noninteresting.h"
#include "Element.h"
#include "myItoA.h"

#include "state_protocol.h"
void state_protocol(ojVal value, struct Context *ctx) {
	if ((value->type == OJ_OBJECT) || (value->type == OJ_ARRAY)) {
		ctx->depth++;
		ctx->stack[ctx->depth] = &state_noninteresting;
	} else if (value->type != OJ_NONE) {
		struct Element *elem;
		char scratchpad[SCRATCHPAD_SIZE];
		const char *find;
		find = oj_key(value); 
		elem = avl_find(ctx->elem_tree, &find);
		if (elem) {
			switch (value->type) {
				case OJ_TRUE:
					free(ctx->items[elem->index]);
					ctx->items[elem->index] = strdup("true");
					break;
				case OJ_FALSE:
					free(ctx->items[elem->index]);
					ctx->items[elem->index] = strdup("false");
					break;
				case OJ_INT:
					free(ctx->items[elem->index]);
					ctx->items[elem->index] = strdup(myItoA(oj_int_get(value), scratchpad));
					break;
				case OJ_STRING:
					free(ctx->items[elem->index]);
					ctx->items[elem->index] = strdup(oj_str_get(value));
					break;
				case OJ_BIG:
					free(ctx->items[elem->index]);
					ctx->items[elem->index] = strdup(oj_bignum_get(value));
					break;
			}
		};
	}
};
