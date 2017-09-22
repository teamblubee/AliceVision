// This file is part of the AliceVision project and is made available under
// the terms of the MPL2 license (see the COPYING.md file).

#pragma once

#include <aliceVision/geometry/Pose3.hpp>

namespace aliceVision {
namespace geometry {

// Define a 3D Similarity transform encoded as a 3D pose plus a scale
struct Similarity3
{
  Pose3 _pose;
  double _scale;

  Similarity3(): _pose(Pose3()), _scale(1.0) {}
  Similarity3(const Pose3 & pose, const double scale) : _pose(pose), _scale(scale) {}

  // Operators
  Vec3 operator () (const Vec3 & point) const
  {
    return _scale * _pose(point);
  }

  Pose3 operator () (const Pose3 & pose) const
  {
    return Pose3( pose.rotation() * _pose.rotation().transpose(), this->operator()(pose.center()));
  }
};

} // namespace geometry
} // namespace aliceVision
