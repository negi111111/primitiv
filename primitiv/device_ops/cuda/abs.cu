#include <primitiv/config.h>

#include <primitiv/core/cuda_device.h>
#include <primitiv/internal/cuda_utils.h>
#include <primitiv/device_ops/cuda/common.h>

namespace {

CUDADEV_KERNEL_FW_X(abs, ::fabsf(px[i]));
CUDADEV_KERNEL_BW_X(abs, ((px[i] > .0f) - (px[i] < .0f)) * pgy[i]);

}  // namespace

namespace primitiv {
namespace devices {

CUDADEV_FW_X(abs);
CUDADEV_BW_X(abs);

}  // namespace devices
}  // namespace primitiv
