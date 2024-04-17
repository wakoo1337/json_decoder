#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "contrib/avl.h"
#include "contrib/oj/oj.h"
#include "json_push.h"
#include "json_pop.h"
#include "Element.h"
#include "Context.h"
#include "compareElements.h"
#include "state_start.h"

int main(int argc, char **argv) {
	int go = 0;
	while (go) sleep(1);
	struct Context context;
	context.depth = 0;
	context.stack[0] = &state_start;
	context.elem_tree = avl_create(&compareElements, NULL, NULL);
	for (int i=1;i < argc;i++) {
		char *token, *save;
		token = strtok_r(argv[i], ",", &save);
		while (token) {
			struct Element *elem;
			elem = malloc(sizeof(struct Element));
			elem->name = token;
			elem->index = i-1;
			avl_probe(context.elem_tree, elem);
			token = strtok_r(NULL, ",", &save);
		};
	};
	context.items_count = argc-1;
	context.items = calloc(context.items_count, sizeof(char *));
	struct _ojErr error = OJ_ERR_INIT;
	oj_pp_parse_fd(&error, STDIN_FILENO, json_push, json_pop, &context);
};
