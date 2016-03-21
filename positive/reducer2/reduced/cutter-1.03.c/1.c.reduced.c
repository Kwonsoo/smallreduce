int ifreq[32];
int ifconf_0, localip_sa;
getifconfig() { ifconf_0 = sizeof ifreq; }

localip() {
  int i = 0;
  while (1) {
    if (!(i < ifconf_0 / sizeof(int)))
      goto while_break;
    airac_observe(ifreq, i);
    localip_sa = i++;
  }
while_break:
  ;
}
