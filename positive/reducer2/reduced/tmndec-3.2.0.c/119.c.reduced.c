int reconstruct_ei_ep_comp;
reconstruct_ei_ep() {
  int cc;
  unsigned prev_frame___0[3];
  cc = reconstruct_ei_ep_comp & 1;
  if (cc == 0)
    airac_observe(prev_frame___0, cc);
}
