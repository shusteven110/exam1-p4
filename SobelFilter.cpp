#include <cmath>

#include "SobelFilter.h"

SobelFilter::SobelFilter(sc_module_name n) : sc_module(n) {
  SC_THREAD(do_filter);
  sensitive << i_clk.pos();
  dont_initialize();
  reset_signal_is(i_rst, false);
}

// sobel mask
// const int mask[MASK_N][MASK_X][MASK_Y] = {{{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}},

//                                           {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}};

void SobelFilter::do_filter() {
  while (true) {
    // for (unsigned int i = 0; i < MASK_N; ++i) {
    //   val[i] = 0;
    // }
    // for (unsigned int v = 0; v < MASK_Y; ++v) {
    //   for (unsigned int u = 0; u < MASK_X; ++u) {
    //     unsigned char grey = (i_r.read() + i_g.read() + i_b.read()) / 3;
    //     for (unsigned int i = 0; i != MASK_N; ++i) {
    //       val[i] += grey * mask[i][u][v];
    //     }
    //   }
    // }
    float temp1 = i_r.read();
    float temp2 = i_r.read();
    float temp3 = i_r.read();
    float result = (temp1/6) + (temp2/3) + (temp3/2);
    // double total = 0;
    // for (unsigned int i = 0; i != MASK_N; ++i) {
    //   total += val[i] * val[i];
    // }
    // int result = (int)(std::sqrt(total));
    o_result.write(result);
    printf("%f\n",result);
    wait(3); //emulate module delay
  }
}
