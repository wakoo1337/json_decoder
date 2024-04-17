#include <string.h>
#include <stdio.h>
#include "contrib/oj/oj.h"
#include "Context.h"
#include "state_protocol.h"
#include "state_noninteresting.h"

#include "state_layers.h"
void state_layers(ojVal value, struct Context *ctx) {
	if (value->type == OJ_OBJECT) {
		const char *protocol;
		protocol = oj_key(value);
		ctx->depth++;
		ctx->stack[ctx->depth] = (strcmp(protocol, "ip") && strcmp(protocol, "tcp") && strcmp(protocol, "udp")) ? &state_noninteresting : &state_protocol;
	} else if (value->type == OJ_ARRAY) {
		ctx->depth++;
		ctx->stack[ctx->depth] = &state_noninteresting;
	}
};
