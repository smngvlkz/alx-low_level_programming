#include "hash_tables.h"

/**
 * shash_table_create - create a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: the hash table you want to add or update the key/value to
 * @key: the key
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node, *new_node, *temp;

	if (!ht || !key || strlen(key) == 0 || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (1);
		}
		node = node->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (!ht->shead)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	} else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	} else
	{
		temp = ht->shead;
		while (temp->snext && strcmp
				(temp->snext->key, key) < 0)
			temp = temp->snext;
		new_node->sprev = temp;
		new_node->snext = temp->snext;
		if (temp->snext)
			temp->snext->sprev = new_node;
		else
			ht->stail = new_node;
		temp->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the hash table you want to look into
 * @key: the key you are looking for
 *
 * Return: the value associated with the element,
 * or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (!ht || !key || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char *comma = "";

	if (!ht)
		return;

	printf("{");
	node = ht->shead;
	while (node)
	{
		printf("%s'%s': '%s'", comma,
				node->key, node->value);
		comma = ", ";
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char *comma = "";

	if (!ht)
		return;

	printf("{");
	node = ht->stail;
	while (node)
	{
		printf("%s'%s': '%s'", comma,
				node->key, node->value);
		comma = ", ";
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;

	if (!ht)
		return;

	node = ht->shead;
	while (node)
	{
		temp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = temp;
	}

	free(ht->array);
	free(ht);
}
