#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;


struct xyCoord {
	int xCoord;
	int yCoord;
};


class Point {
private:
	int xCoord;
	int yCoord;
	int label;

public:
	Point() {
		xCoord = 0;
		yCoord = 0;
		label = 0;
	
	}

	Point(int x, int y) {
		xCoord = x;
		yCoord = y;
		label = 0;
	}
	Point(const Point& pt) {
		xCoord = pt.xCoord;
		yCoord = pt.yCoord;
		label = pt.label;


	}
	void setLabel(int l) {
		label = l;
	}
	int getX() {
		return xCoord;
	}
	int getY() {

		return yCoord;
	}
	int getLabel() {
		return label;
	}

};

class Kmean {
private:
	int Kcluster;
	int numPts;
	Point* ptList;
	int changeFlag;
	xyCoord* kCentroids;

public:
	Kmean() {
		Kcluster = 0;
		numPts = 0;
		changeFlag = 0;
	}
	Kmean(int k, int n) {
		Kcluster = k;
		numPts = n;
		ptList = new Point[numPts];
		changeFlag = 0;
		kCentroids = new xyCoord[Kcluster];

	}

	//Enters a piont into the ptList
	void loadPtList(int count, Point pt) {
		ptList[count] = pt;

	}

	//
	void assignLabel() {
		int ptCount = 0;
		int kCount = 1;
		while (ptCount < numPts) {
			ptList[ptCount].setLabel(kCount);
			kCount++;
			if (kCount > Kcluster) {
				kCount = 1;
				ptCount++;
			}
		}
	}
	void computeCentroid() {
		int * sumCnt = new int[Kcluster + 1];
		int* sumX = new int[Kcluster + 1];
		int * sumY = new int[Kcluster + 1];
		for (int i = 0; i <= Kcluster; i++) {
			sumCnt[i] = 0;
			sumX[i] = 0;
			sumY[i] = 0;
		}

		int ptIndex = 0;
		while (ptIndex < numPts) {
			int label = ptList[ptIndex].getLabel();
			sumX[label] += ptList[ptIndex].getX();
			sumY[label] += ptList[ptIndex].getY();
			sumCnt[label]++;
			ptIndex++;

		}

		int clusterIndext = 1;

		while (clusterIndext <= Kcluster) {
			kCentroids[clusterIndext].xCoord = sumX[clusterIndext] / sumCnt[clusterIndext];
			kCentroids[clusterIndext].yCoord = sumY[clusterIndext] / sumCnt[clusterIndext];
			clusterIndext++;
		}
	}

	// checks whether all points need to change labels
	void clusterCheck() {
		double * dist = new double[Kcluster + 1];
	}


	double computeDist(Point p1, xyCoord p2) {
		double xDiff = (double)p1.getX() - p2.xCoord;
		double yDiff = (double)p1.getY() - p2.yCoord;
		double dist = sqrt((xDiff*xDiff) + (yDiff*yDiff));
			return dist;
	}




};



class image {
private: 
	int numRows;
	int numCols;
	int** imgAry;
};




int main() {

}





















