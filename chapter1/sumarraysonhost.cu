#include "cuda_util.h"

int main() {
  CHECK_CUDA(cudaSetDevice(0));
  return 0;
}