#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contrib/oj/oj.h"
#include "Context.h"

#include "json_push.h"
void json_push(ojVal value, void *user) {
	struct Context *ctx = (struct Context *) user;
	ctx->stack[ctx->depth](value, ctx);
};
