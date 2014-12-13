#include <iostream>
#include <string>

#include "floorplan.h"

using namespace Eigen;
using namespace std;

namespace {

istream& operator>>(std::istream& istr, Triangle& triangle) {
  for (int i = 0; i < 3; ++i) {
    istr >> triangle.indices[i];
  }
  istr >> triangle.image_index;
  for (int i = 0; i < 3; ++i) {
    istr >> triangle.uvs[i][0] >> triangle.uvs[i][1];
  }
  return istr;
}

istream& operator>>(std::istream& istr, LineRoom& line_room) {
  int num_words;
  istr >> num_words;
  if (num_words != 0) {
    line_room.name.resize(num_words);
    for (int w = 0; w < num_words; ++w)
      istr >> line_room.name[w];
  }
  int num_vertices;
  istr >> num_vertices;
  
  line_room.vertices.resize(num_vertices);
  for (int p = 0; p < num_points; ++p) {
    istr >> line_room.vertices[p][0] >> line_room.vertices[p][1];
  }
  
  istr >> line_room.floor_height
       >> line_room.ceiling_height;

  wall_triangulations.resize(num_points);
  for (int w = 0; w < num_points; ++w)
    istr >> wall_triangulations[w];

  istr >> floor_triangulation;
  istr >> ceiling_triangulation;
  return istr;
}

std::istream& operator>>(std::istream& istr, WallTriangulation& wall_triangulation) {
  int num_vertices, num_triangles;
  istr >> num_vertices >> num_triangles;
  wall_triangulation.vertices_in_uv.resize(num_vertices);
  for (int v = 0; v < num_vertices; ++v) {
    istr >> wall_triangulation.vertices_in_uv[v][0]
         >> wall_triangulation.vertices_in_uv[v][1];
  }
  wall_triangulation.triangles.resize(num_triangles);
  for (int t = 0; t < num_triangles; ++t) {
    istr >> wall_triangulation.triangles[t];
  }

  return istr;
}

std::istream& operator>>(std::istream& istr, FloorCeilingTriangulation& triangulation) {
  int num_triangles;
  istr >> num_triangles;
  triangulation.triangles.resize(num_triangles);
  for (int t = 0; t < num_triangles; ++t) {
    istr >> triangulation.triangles[t];
  }

  return istr;
}

istream& operator>>(istream& istr, LineDoor& line_door) {
  for (int i = 0; i < 2; ++i) {
    istr >> line_door.line_door_faces[i].room_id
         >> line_door.line_door_faces[i].wall_id;
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      istr >> line_door.line_door_faces[i].vertex_indices[j];
    }
  }

  const int kNumTriangles = 8;
  for (int t = 0; t < kNumTriangles; ++t) {
    istr >> line_door.triangles[t];
  }
  
  return istr;
}
  
//----------------------------------------------------------------------
//----------------------------------------------------------------------
istream& operator>>(istream& istr, Shape& shape) {
  int vnum;
  istr >> vnum;
  shape.vertices.resize(vnum);
  for (auto& vertex : shape.vertices) {
    istr >> vertex[0] >> vertex[1];
  }
  int fnum;
  istr >> fnum;
  shape.faces.resize(fnum);
  for (auto& face : shape.faces) {
    istr >> face[0] >> face[1] >> face[2];
  }
  return istr;
}

ostream& operator<<(ostream& ostr, const Shape& shape) {
  ostr << shape.vertices.size() << endl;
  for (const auto& vertex : shape.vertices) {
    ostr << vertex[0] << ' ' << vertex[1] << endl;
  }
  ostr << shape.faces.size() << endl;
  for (const auto& face : shape.faces) {
    ostr << face[0] << ' ' << face[1] << ' ' << face[2] << endl;
  }
  return ostr;
}
  
}  // namespace

const Eigen::Matrix3d& GetFloorplanToGlobal() const {
  return floorplan_to_global;
}

Eigen::Vector2d LineFloorplan::GetRoomVertexLocal(const int room, const int vertex) const {
  return line_rooms[room].vertices[vertex];
}

Eigen::Vector3d LineFloorplan::GetFloorVertexGlobal(const int room, const int vertex) const {
  const Eigen::Vector2d local = GetRoomVertexLocal(room, vertex);
  return floorplan_to_global * Eigen::Vector3d(local[0], local[1], line_rooms[room].floor_height);
}

Eigen::Vector3d LineFloorplan::GetCeilingVertexGlobal(const int room, const int vertex) const {
  const Eigen::Vector2d local = GetRoomVertexLocal(room, vertex);
  return floorplan_to_global * Eigen::Vector3d(local[0], local[1], line_rooms[room].ceiling_height);
}

Eigen::Vector3d LineFloorplan::GetWallVertexGlobal(const int room, const int wall, const int vertex) const {
  const int v0 = wall;
  const int v1 = (wall + 1) % line_rooms[room].vertices.size();
  const Eigen::Vector3d v00 = GetFloorVertexGlobal(room, v0);
  const Eigen::Vector3d v01 = GetFloorVertexGlobal(room, v1);
  const Eigen::Vector3d v11 = GetCeilingVertexGlobal(room, v1);
  const Eigen::Vector3d v10 = GetCeilingVertexGlobal(room, v0);

  const Eigen::Vector2d& uv = line_rooms[room].wall_triangulations[wall].vertices_in_uv[vertex];
  // Must handle the 4 corner case exactly to avoid numerical errors.
  if (uv[0] == 0.0 && uv[1] == 0.0)
    return v00;
  else if (uv[0] == 0.0 && uv[1] == 1.0)
    return v10;
  else if (uv[0] == 1.0 && uv[1] == 0.0)
    return v01;
  else if (uv[0] == 1.0 && uv[1] == 1.0)
    return v11;
  else
    return v00 + (v01 - v00) * uv[0] + (v10 - v00) * uv[1];
}

Eigen::Vector3d LineFloorplan::GetDoorVertexGlobal(const int door, const int vertex) const {
  const int face = vertex / 4;
  const int face_vertex = vertex % 4;

  const int wall_vertex = line_doors[door].line_door_faces[face].vertex_indices[face_vertex];
  const int room = line_doors[door].line_door_faces[face].room_id;
  const int wall = line_doors[door].line_door_faces[face].wall_id;
  return GetWallVertexGlobal(room, wall, wall_vertex);
}

const Triangle& LineFloorplan::GetFloorTriangle(const int room, const int triangle) const {
  return line_rooms[room].floor_triangulation.triangles[triangle];
}

const Triangle& LineFloorplan::GetCeilingTriangle(const int room, const int triangle) const {
  return line_rooms[room].ceiling_triangulation.triangles[triangle];
}

const Triangle& LineFloorplan::GetWallTriangle(const int room, const int wall, const int triangle) const {
  return line_rooms[room].wall_triangulations[wall].triangles[triangle];
}

const Triangle& LineFloorplan::GetDoorTriangle(const int door, const int triangle) const {
  return line_doors[door].triangles[triangle];
}

double LineFloorplan::GetFloorHeight(const int room) const {
  return line_rooms[room].floor_height;
}

double LineFloorplan::GetCeilingHeight(const int room) const {
  return line_rooms[room].ceiling_height;
}

int LineFloorplan::GetNumRooms() const {
  return static_cast<int>(line_rooms.size());
}
int LineFloorplan::GetNumRoomVertices(const int room) const {
  return static_cast<int>(line_rooms[room].vertices.size());
}
int LineFloorplan::GetNumWalls(const int room) const {
  retrun GetNumRoomVertices(room);
}
int LineFloorplan::GetNumWallVertices(const int room, const int wall) const {
  return static_cast<int>(line_rooms[room].wall_triangulations[wall].vertices_in_uv.size());
}
int LineFloorplan::GetNumDoors() {
  return static_cast<int>(line_doors.size());
}
int LineFloorplan::GetNumDoorVertices(const int door) {
  return 8;
}
int LineFloorplan::GetNumDoorTriangles(const int door) {
  return 8;
}

int LineFloorplan::GetNumWallTriangles(const int room, const int wall) const {
  return static_cast<int>(line_rooms[room].wall_triangulations[wall].triangles.size());
}
int LineFloorplan::GetNumFloorTriangles(const int room) const {
  return static_cast<int>(line_rooms[room].floor_triangulation.triangles.size());
}
int LineFloorplan::GetNumCeilingTriangles(const int room) const {
  return static_cast<int>(line_rooms[room].ceiling_triangulation.triangles.size());
}

//----------------------------------------------------------------------
istream& operator>>(istream& istr, LineFloorplan& line_floorplan) {
  for (int y = 0; y < 3; ++y)
    for (int x = 0; x < 3; ++x)
      istr >> line_floorplan.floorplan_to_global(y, x);
  
  int num_rooms;
  istr >> num_rooms;
  line_floorplan.line_rooms.resize(num_rooms);

  for (int r = 0; r < num_rooms; ++r)
    istr >> line_floorplan.line_rooms[r];

  int num_doors;
  istr >> num_doors;
  line_floorplan.line_doors.resize(num_doors);
  for (int d = 0; d < num_doors; ++d) {
    istr >> line_floorplan.line_doors[d];
  }

  return istr;
}
  
istream& operator>>(istream& istr, Floorplan& floorplan) {
  string header;
  int component_num;
  istr >> header
       >> floorplan.floor_height
       >> component_num;

  floorplan.components.resize(component_num);
  for (auto& component : floorplan.components) {
    istr >> component.outer_shape;
    int inner_shape_num;
    istr >> inner_shape_num;
    component.inner_shapes.resize(inner_shape_num);
    for (auto& inner_shape : component.inner_shapes) {
      istr >> inner_shape;
    }
  }
  
  return istr;
}

ostream& operator<<(ostream& ostr, const Floorplan& floorplan) {
  ostr << "FLOORPLAN" << endl
       << floorplan.floor_height << endl
       << floorplan.components.size() << endl;
  // Components.
  for (const auto& component : floorplan.components) {
    // outer_shape.
    ostr << component.outer_shape;
    // inner_shapes.
    ostr << component.inner_shapes.size() << endl;
    for (const auto& shape : component.inner_shapes) {
      ostr << shape << endl;
    }
  }
  // Room interiors.
  
  return ostr;
}

