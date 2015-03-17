#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

#include <gflags/gflags.h>

#include "../base/file_io.h"
#include "../base/floorplan.h"
// #include "../base/indoor_polygon.h"
#include "../base/panorama.h"
#include "../base/point_cloud.h"
#include "detection.h"

using namespace Eigen;
using namespace std;
using namespace structured_indoor_modeling;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " data_directory" << endl;
    return 1;
  }
#ifdef __APPLE__
  google::ParseCommandLineFlags(&argc, &argv, true);
#else
  gflags::ParseCommandLineFlags(&argc, &argv, true);
#endif

  FileIO file_io(argv[1]);
  
  vector<Panorama> panoramas;
  {
    ReadPanoramas(file_io, &panoramas);
  }

  vector<Detection> detections;
  {
    ifstream ifstr;
    ifstr.open(file_io.GetObjectDetections().c_str());
    if (!ifstr.is_open()) {
      cerr << "File cannot be opened: " << file_io.GetObjectDetections() << endl;
      return 1;
    }
    ifstr >> detections;
    ifstr.close();
  }

  vector<PointCloud> object_point_clouds;
  {
    Floorplan floorplan(file_io.GetFloorplan());
    ReadObjectPointClouds(file_io, floorplan.GetNumRooms(), &object_point_clouds);
  }
  
  // Find the corresponding object point cloud, and compute the icon information for the viewer.

  // For each detection, find the most relevant object point cloud if any.
  ///  vector<ObjectPointCloud>

  

  /*
  vecor<PointCloud> input_point_clouds, object_point_clouds;
  ReadPointClouds(file_io, &input_point_clouds);
  ReadObjectPointClouds(file_io, floorplan.GetNumRooms(), &object_point_clouds);

  // Accuracy and completeness.
  const RasterizedGeometry kInitial(numeric_limits<double>::max(), Vector3d(0, 0, 0), kHole);

  std::vector<std::vector<RasterizedGeometry> > rasterized_geometries;

  double depth_unit = 0.0;
  for (int p = 0; p < panoramas.size(); ++p)
    depth_unit += panoramas[p].GetAverageDistance();
  depth_unit /= panoramas.size();
  
  //----------------------------------------------------------------------
  if (FLAGS_evaluate_floorplan) {
    // Floorplan only.
    Initialize(panoramas, kInitial, &rasterized_geometries);
    RasterizeFloorplan(floorplan, panoramas, &rasterized_geometries);
    VisualizeResults(file_io, "floorplan", input_point_clouds, rasterized_geometries, panoramas, kInitial.depth, depth_unit);
    ReportErrors(input_point_clouds,
                 rasterized_geometries,
                 panoramas,
                 kInitial,
                 depth_unit);
  }

  
  // Indoor polygon only.
  if (FLAGS_evaluate_indoor_polygon) {
    Initialize(panoramas, kInitial, &rasterized_geometries);
    RasterizeIndoorPolygon(indoor_polygon, panoramas, &rasterized_geometries);
    VisualizeResults(file_io, "indoor_polygon", input_point_clouds, rasterized_geometries, panoramas, kInitial.depth, depth_unit);
    ReportErrors(input_point_clouds,
                 rasterized_geometries,
                 panoramas,
                 kInitial,
                 depth_unit);

    if (FLAGS_evaluate_object_point_clouds) {
      // Plus objects.
      RasterizeObjectPointClouds(object_point_clouds, panoramas, &rasterized_geometries);
      VisualizeResults(file_io, "object_point_clouds", input_point_clouds, rasterized_geometries, panoramas, kInitial.depth, depth_unit);
      ReportErrors(input_point_clouds,
                   rasterized_geometries,
                   panoramas,
                   kInitial,
                   depth_unit);
    }
  }
  */  
  return 0;
}
