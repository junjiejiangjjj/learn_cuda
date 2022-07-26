#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cuda_runtime_api.h>

#define CHECK_CUDA(call)                                                \
  do {                                                                  \
    CudaStatus s(call);                                                 \
    if (!s.IsOk()) {                                                    \
      std::cout << "CUDA Runtime failure: '#" << s.Msg() << "' at " <<  __FILE__ << ":" << __LINE__ << std::endl; \
      return false;                                                     \
    }                                                                   \
  } while (false)                                                       \

int DevMalloc(void **p, size_t s);
int DevFree(void *p);
int HostMalloc(void** p, size_t s, unsigned int f);
int HostFree(void* p);


class CudaStatus {
public:
   explicit CudaStatus(cudaError_t error) : mCode(error) {}
   
   CudaStatus(CudaStatus&) = default;
   CudaStatus& operator=(CudaStatus&) = default;
   
   bool IsOk() {
     return mCode == cudaSuccess;
   }
   
   std::string Msg() {
     return cudaGetErrorString(mCode);
   }

private:
   cudaError_t mCode;
};
