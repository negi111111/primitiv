#include <primitiv/config.h>

#include <primitiv/core/eigen_device.h>
#include <primitiv/device_ops/eigen/common.h>

namespace primitiv {
namespace devices {

void Eigen::batch_pick_fw_impl(
    const Tensor &x, const std::vector<std::uint32_t> &ids, Tensor &y) {
  // TODO(chantera): Optimize this functions using Eigen operations.

  const std::uint32_t bs = y.shape().batch();
  const std::uint32_t span = x.shape().volume();

  float *dest = MDATA(y);
  for (std::uint32_t batch = 0; batch < bs; ++batch) {
    const float *src = CDATA(x) + span * ids[batch];
    std::copy(src, src + span, dest);
    dest += span;
  }
}

void Eigen::batch_pick_bw_impl(
    const Tensor &gy, const std::vector<std::uint32_t>& ids, Tensor &gx) {
  // TODO(chantera): Optimize this functions using Eigen operations.

  const std::uint32_t bs = gy.shape().batch();
  const std::uint32_t span = gx.shape().volume();

  const float *src = CDATA(gy);
  for (std::uint32_t batch = 0; batch < bs; ++batch) {
    float *dest = MDATA(gx) + span * ids[batch];
    REPEAT_OP(i, span, *dest++ += *src++);
  }
}

}  // namespace devices
}  // namespace primitiv
