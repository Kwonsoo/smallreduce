int RoomSaved[16];
LoadGame() {
  int ct = 0;
  while (1) {
    if (!(ct < 16))
      goto while_break;
    airac_observe(RoomSaved, ct);
    ct++;
  }
while_break:
  ;
}
