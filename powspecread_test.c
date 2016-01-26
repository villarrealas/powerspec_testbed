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
