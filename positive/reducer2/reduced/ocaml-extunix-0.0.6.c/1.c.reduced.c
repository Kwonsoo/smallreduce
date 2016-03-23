int caml_extunix_ioctl_siocgifconf_ifconf_0;
caml_extunix_ioctl_siocgifconf() {
  int ifreqs[32];
  int i;
  caml_extunix_ioctl_siocgifconf_ifconf_0 = sizeof ifreqs;
  i = 0;
  while (1) {
    if (!(i < caml_extunix_ioctl_siocgifconf_ifconf_0 / sizeof(int)))
      goto while_break;
    airac_observe(ifreqs, i);
    i++;
  }
while_break:
  ;
}
