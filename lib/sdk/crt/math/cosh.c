/* Copyright (C) 1994 DJ Delorie, see COPYING.DJ for details */
#include <math.h>

#ifdef _MSC_VER
#pragma function(cosh)
#endif

/*
 * @implemented
 */
double cosh(double x)
{
    const double ebig = exp(fabs(x));
    return (ebig + 1.0/ebig) / 2.0;
}
