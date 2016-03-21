struct player_pieces {
  int size;
  struct player_pieces *body;
} snake;
void *player_increase_size_tmp;
nsnake_init() { player_increase_size(2); }

player_increase_size(p1) {
  snake.size += p1;
  int i;
  snake.size = 3;
  player_increase_size_tmp = malloc(snake.size * sizeof(struct player_pieces));
  snake.body = player_increase_size_tmp;
  i = 0;
  while (1) {
    if (!(i < snake.size))
      goto while_break;
    airac_observe(snake.body, i);
    i++;
  }
while_break:
  ;
}
