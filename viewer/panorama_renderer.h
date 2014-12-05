#ifndef PANORAMA_RENDERER_H__
#define PANORAMA_RENDERER_H__

#include <vector>
#include <Eigen/Dense>
#include <QImage>
#include <QGLFunctions>
#include <QGLWidget>

#include "configuration.h"

class PanoramaRenderer : protected QGLFunctions {
 public:
  PanoramaRenderer();
  virtual ~PanoramaRenderer();
  void Render();
  void Init(const PanoramaConfiguration& panorama_configuration, QGLWidget* widget);
  void InitGL();
  Eigen::Vector2d Project(const Eigen::Vector3d& xyz) const;
  Eigen::Vector3d Unproject(const Eigen::Vector2d& uv, const double distance) const;

  Eigen::Vector3d GlobalToLocal(const Eigen::Vector3d& global_xyz) const;
  Eigen::Vector3d LocalToGlobal(const Eigen::Vector3d& local_xyz) const;

  const Eigen::Vector3d& GetCenter() const { return center; }

 private:
  void InitDepthMesh(const std::string& filename, const double phi_range);

  // For texture allocation and deletion.
  QGLWidget* widget;
  
  // Image.
  QImage rgb_image;
  GLint texture_id;

  // Depthmap is turned into a grid mesh.
  int depth_width;
  int depth_height;
  std::vector<Eigen::Vector3d> depth_mesh;

  // Camera position.
  Eigen::Vector3d center;
  // Camera rotation.
  Eigen::Matrix3d local_to_global;
  Eigen::Matrix3d global_to_local;
  // Camera intrinsics: phi (in radian) per image y.
  float phi_per_pixel;
  float depth_phi_per_pixel;

};

#endif  // PANORAMA_RENDERER_H__