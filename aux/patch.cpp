#include "patch.h"

//Patch::Patch(const Eigen::Vector3d& p,const Eigen::Vector3d& n,const unsigned int& nIm,
//      const Eigen::Vector3i& inds)
//  : point_(p),normal_(n),nImgs_(nIm),inds_(inds)
//  {}
Patch::Patch(const Patch& p)
  : point_(p.getPoint()),
    pointInd_(p.getPointInd()),
    normal_(p.getNormal),
    nImgs_(p.getNImages()),
    inds_(p.getInds())
  {}

Patch& Patch::operator= (const Patch& p){
  point_ = p.getPoint();
  pointInd_ = p.getPointInd();
  normal_ = p.getNormal();
  nImgs_ = p.getNImages();
  top3_ = p.getTop3();
  return *this;
}
 
bool operator==(Patch& p1, pcl::PointXYZ& p2){
  return ((p1.point_[0]==p2[0]) &&
          (p1.point_[1]==p2[1]) &&
          (p1.point_[2]==p2[2]));
}
bool operator==(pcl::PointXYZ& p1, Patch& p2){
  return ((p2.point_[0]==p1[0]) &&
          (p2.point_[1]==p1[1]) &&
          (p2.point_[2]==p1[2]));
}

bool operator!=(Patch& p1, pcl::PointXYZ& p2){
  return ((p1.point_[0]!=p2[0]) ||
          (p1.point_[1]!=p2[1]) ||
          (p1.point_[2]!=p2[2]));
}
bool operator!=(pcl::PointXYZ& p1, Patch& p2){
  return ((p2.point_[0]!=p1[0]) ||
          (p2.point_[1]!=p1[1]) ||
          (p2.point_[2]!=p1[2]));
}
