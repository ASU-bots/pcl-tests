#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <cmath>

int main(int argc, char** argv){
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
	
	//pcl::PointCloud<pcl::PointXYZRGB>* cloud= new pcl::PointCloud<pcl::PointXYZRGB>
	if(argc==2){
	if(pcl::io::loadPCDFile<pcl::PointXYZRGB>(argv[1],*cloud) == -1){
		PCL_ERROR("Couldn't read file.");
		return -1;
	}

	std::cout << "Loaded"
		  << cloud->width * cloud->height
		  << " data points.";

	/*for(size_t i=0;i<cloud->points.size(); i++){
		std::cout<< "    " << cloud->points[i].x
			 << " "    << cloud->points[i].y
			 << " "    << cloud->points[i].z
			 << " "    << cloud->points[i].rgb << "\n";
	}*/

	pcl::visualization::CloudViewer viewer("Chess");
	viewer.showCloud(cloud);
	while(!viewer.wasStopped()){
	}
	}
	else{
		srand (time(NULL));
		
		for(int i=0;i<500000;i++){
			pcl::PointXYZRGB pt;
			pt.x=(rand())*(100.0/RAND_MAX);
			pt.y=(rand())*(100.0/RAND_MAX);
			pt.z=(rand())*(100.0/RAND_MAX);
			int mx=pt.x-50;int my=pt.y-50;int mz=pt.z-50;
			float vpos=sqrt(mx*mx+my*my+mz*mz);
			pt.x=pt.x*86/(1+vpos);
			pt.y=pt.y*86/(1+vpos);
			pt.z=pt.z*86/(1+vpos);
			pt.r=rand()%255;
			pt.g=rand()%255;
			pt.b=rand()%255;
			cloud->push_back(pt);
			//std::cout<<i;
		}
		
		pcl::visualization::CloudViewer viewer("Rand");
		viewer.showCloud(cloud);

		

		while(!viewer.wasStopped()){
				}
	}


	return 0;
			
}
