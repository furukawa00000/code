#ifndef STRUCTURED_INDOOR_MODELING_SYNTHESIZE_H_
#define STRUCTURED_INDOOR_MODELING_SYNTHESIZE_H_

#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <vector>

namespace structured_indoor_modeling {

struct SynthesisData {
  Eigen::Vector2i texture_size;
  int patch_size;
  int margin;

  std::vector<cv::Mat> projected_textures;
  std::vector<bool> mask;

  int num_cg_iterations;
};

void CollectCandidatePatches(const SynthesisData& synthesis_data,
                             std::vector<cv::Mat>* patches);

void SynthesizePoisson(const SynthesisData& synthesis_data,
                       const std::vector<cv::Mat>& patches,
                       cv::Mat* floor_texture);

void SynthesizeQuilt(const SynthesisData& synthesis_data,
                     const std::vector<cv::Mat>& patches,
                     cv::Mat* floor_texture);
 
}  // namespace structured_indoor_modeling

#endif  // STRUCTURED_INDOOR_MODELING_SYNTHESIZE_H_
