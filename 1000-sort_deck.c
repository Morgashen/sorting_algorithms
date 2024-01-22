#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

int compare_cards(const void *a, const void *b) {
  deck_node_t *node_a = *(deck_node_t **)a;
  deck_node_t *node_b = *(deck_node_t **)b;

  card_t card_a = node_a->card;
  card_t card_b = node_b->card;


  if (card_a.rank < card_b.rank) {
    return -1;
  } else if (card_a.rank > card_b.rank) {
    return 1;
  } else {

    if (card_a.suit < card_b.suit) {
      return -1;
    } else if (card_a.suit > card_b.suit) {
      return 1;
    } else {

      return 0;
    }
  }
}


void sort_deck(deck_node_t **deck) {

  if (*deck == NULL || (*deck)->next == NULL) {
    return;
  }


  deck_node_t *array[52];
  int i = 0;
  deck_node_t *current = *deck;
  while (current != NULL) {
    array[i] = current;
    i++;
    current = current->next;
  }


  qsort(array, 52, sizeof(deck_node_t *), compare_cards);


  for (i = 0; i < 51; i++) {
    array[i]->next = array[i + 1];
    array[i + 1]->prev = array[i];
  }
  array[0]->prev = NULL;
  array[51]->next = NULL;


  *deck = array[0];
}
