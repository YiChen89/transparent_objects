/*
 * pclProcessing.hpp
 *
 *  Created on: Nov 21, 2011
 *      Author: Ilya Lysenkov
 */

#ifndef PCLPROCESSING_HPP_
#define PCLPROCESSING_HPP_

#include <pcl/pcl_base.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/ModelCoefficients.h>

#include <opencv2/core/core.hpp>

void downsample(float downLeafSize, pcl::PointCloud<pcl::PointXYZ> &cloud);
void downsample(float downLeafSize, const pcl::PointCloud<pcl::PointXYZ> &inCloud, pcl::PointCloud<pcl::PointXYZ> &outCloud);

void estimateNormals(int kSearch, const pcl::PointCloud<pcl::PointXYZ> &cloud, pcl::PointCloud<pcl::Normal> &normals);

bool segmentTable(float distanceThreshold, const pcl::PointCloud<pcl::PointXYZ> &cloud, const pcl::PointCloud<pcl::Normal> &normals, pcl::PointIndices::Ptr &inliers, pcl::ModelCoefficients::Ptr &coefficients);

void projectInliersOnTable(const pcl::PointCloud<pcl::PointXYZ> &cloud, const pcl::PointIndices::ConstPtr &inliers, const pcl::ModelCoefficients::ConstPtr &coefficients, pcl::PointCloud<pcl::PointXYZ> &projectedInliers);

void reconstructConvexHull(const pcl::PointCloud<pcl::PointXYZ> &projectedInliers, pcl::PointCloud<pcl::PointXYZ> &tableHull);

void extractPointCloud(const pcl::PointCloud<pcl::PointXYZ> &cloud, const pcl::PointIndices::ConstPtr &inliers, pcl::PointCloud<pcl::PointXYZ> &extractedCloud);

void segmentObjects(float minZ, float maxZ, const pcl::PointCloud<pcl::PointXYZ> &cloud, const pcl::PointCloud<pcl::PointXYZ> &tableHull, pcl::PointIndices::Ptr objectsIndices);

void rotateTable(const pcl::ModelCoefficients::Ptr &coefficients, pcl::PointCloud<pcl::PointXYZ> &sceneCloud, pcl::PointCloud<pcl::PointXYZ> &projectedInliers, pcl::PointCloud<pcl::PointXYZ> &tableHull);

bool computeTableOrientation(int kSearch, float distanceThreshold, const pcl::PointCloud<pcl::PointXYZ> &fullSceneCloud, cv::Vec4f &tablePlane, pcl::PointCloud<pcl::PointXYZ> *tableHull = 0, float clusterTolerance = 0.05f, cv::Point3f verticalDirection = cv::Point3f(0.0f, -1.0f, 0.0f));

#endif /* PCLPROCESSING_HPP_ */
