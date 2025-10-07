#include <time.h>
#include <math.h>
#include "fee.h"

double calcFee(long start, long end) {
    double hrs = difftime(end, start) / 3600.0;
    if (hrs <= 1.0) return 20.0;
    return 20.0 + ceil(hrs - 1.0) * 15.0;
}
