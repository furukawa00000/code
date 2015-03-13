#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

#include <gflags/gflags.h>

#include "../base/file_io.h"
#include "../base/floorplan.h"
#include "../base/indoor_polygon.h"
#include "../base/panorama.h"
#include "../base/point_cloud.h"
#include "evaluate.h"

DEFINE_string(floorplan_file, "", "Floorplan filename.");
DEFINE_string(indoor_polygon_file, "", "Indoor_polygon filename.");

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
  
  string floorplan_file;
  if (FLAGS_floorplan_file == "") {
    floorplan_file = file_io.GetFloorplan();
  } else {
    char buffer[1024];
    sprintf(buffer, "%s/%s", argv[1], FLAGS_floorplan_file.c_str());
    floorplan_file = buffer;
  }

  string indoor_polygon_file;
  if (FLAGS_indoor_polygon_file == "") {
    indoor_polygon_file = file_io.GetIndoorPolygon();
  } else {
    char buffer[1024];
    sprintf(buffer, "%s/%s", argv[1], FLAGS_indoor_polygon_file.c_str());
    indoor_polygon_file = buffer;
  }
  
  Floorplan floorplan(floorplan_file);
  IndoorPolygon indoor_polygon(indoor_polygon_file);

  vector<Panorama> panoramas;
  ReadPanoramas(file_io, &panoramas);
  // Adjust the center of panorama to the center of the laser scanner.
  for (int p = 0; p < panoramas.size(); ++p) {
    panoramas[p].AdjustCenter(GetLaserCenter(file_io, p));
  }  

  vector<PointCloud> input_point_clouds, object_point_clouds;
  ReadInputPointClouds(file_io, &input_point_clouds);
  ReadObjectPointClouds(file_io, floorplan.GetNumRooms(), &object_point_clouds);

  // Accuracy and completeness.
  //
  // Rasterize from the floorplan data, input_point_clouds
  const RasterizedGeometry kInitial(numeric_limits<double>::max(), Vector3d(0, 0, 0), kHole);

  
  Initialize(panoramas, kInitial, rasterized_geometries);
  
  for (int p = 0; p < (int)input_point_clouds.size(); ++p) {
    const int width  = panoramas[p].DepthWidth();
    const int height = panoramas[p].DepthHeight();


    // Report errors in different configurations.
    {
    
      RasterizeFloorplan(floorplan, rasterized_geometry
  
  }

  return 0;
}
