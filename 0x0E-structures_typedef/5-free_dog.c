#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees the dogs
 * @d: pointer to to free the dog
 */

void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
