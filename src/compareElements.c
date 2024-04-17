#include <string.h>

#include "Element.h"
#include "compareElements.h"
int compareElements(const struct Element *a, const struct Element *b, void *futile) {
	return strcmp(a->name, b->name);
}
