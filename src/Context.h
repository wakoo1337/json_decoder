struct Context {
	unsigned int depth;
	void (*stack[100])(ojVal value, struct Context *ctx);
	struct avl_table *elem_tree;
	char **items;
	unsigned int items_count;
};
