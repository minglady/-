#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <ros/ros.h>
#include <ros/console.h>
#include <Eigen/Eigen>
#include "backward.hpp"

#define inf 1>>20
struct GridNode;
typedef GridNode* GridNodePtr;

struct GridNode
{     
    int id;        // 1--> open set, -1 --> closed set
    Eigen::Vector3d coord; //位于地图中的真实位置
    Eigen::Vector3i dir;   // direction of expanding
    Eigen::Vector3i index;//索引值，可以访问此节点
	
    double gScore, fScore;
    GridNodePtr cameFrom;//father node
    std::multimap<double, GridNodePtr>::iterator nodeMapIt;//container allow repeated key-values,based key resort

    GridNode(Eigen::Vector3i _index, Eigen::Vector3d _coord){  
		id = 0;
		index = _index;
		coord = _coord;
		dir   = Eigen::Vector3i::Zero();

		gScore = inf;//初始化为无穷大
		fScore = inf;//初始化为无穷大
		cameFrom = NULL;
    }

    GridNode(){};
    ~GridNode(){};
};


#endif
