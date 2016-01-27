// we need to make a code to read in a power spectrum file as our first
// step.
//
// This file has four columns:
// z, k [h/Mpc], P(k) [(Mpc/h)^3], and Delta^2(k)
// it has a header column w/ a % as a marker not to be read.
//
// we need to read in the z, k, and P(k) values. We need to change
// to appropriate units for the problem. z -> a, k -> kintern at
// the very least.

#include <stdio.h>
#include <math.h>

int main()
{
  int i, ignoren, counter;
  double ztemp[10000], atemp[10000], ktemp[10000], ptemp[10000], dtemp[10000];
  char ignore[1024];

  FILE *powfile;

  ignoren = 1; // number of header lines

  powfile = fopen("testspec.dat", "r");

  // first step - skip the header. This is clumsy as all hell.
  i = 0;
  while (i < ignoren)
  {
    fgets(ignore, sizeof(ignore), powfile);
    i++;
  }

  // next step - read formatted data until EoF
  i = 0;
  while (fscanf(powfile, "%lf %lf %lf %lf", &ztemp[i], &ktemp[i], &ptemp[i], &dtemp[i]) != EOF)
  {
    i++;
  }
  counter = i;

  i = 0;
  while (i < counter)
  {
    atemp[i] = 1.0 / (1.0 + ztemp[i]);
    fprintf(stdout, "%lf %lf %lf %lf\n", atemp[i], ktemp[i], ptemp[i], dtemp[i]);
    i++;
  }

}
