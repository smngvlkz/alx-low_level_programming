#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table you want to add or update the key/value to
 * @key: the key
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *n_node, *c_node;

	if (!ht || !key || strlen(key) == 0 || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	c_node = ht->array[index];


	while (c_node)
	{
		if (strcmp(c_node->key, key) == 0)
		{
			free(c_node->value);
			c_node->value = strdup(value);
			return (1);
		}
		c_node = c_node->next;
	}

	n_node = malloc(sizeof(hash_node_t));
	if (!n_node)
		return (0);

	n_node->key = strdup(key);
	n_node->value = strdup(value);
	n_node->next = ht->array[index];
	ht->array[index] = n_node;

	return (1);
}
