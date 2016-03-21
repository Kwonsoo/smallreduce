int rts[1024];
int rts_top;
read_routes() { r_route(); }

r_route() {
  if (rts_top >= 1024)
    return;
  airac_observe(rts, rts_top);
  rts_top++;
}
