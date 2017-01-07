/*Name: Floyd 
Compiler: Dev-C++ 5.8.0
Coded by: Jianyu Chen
Place: Middelburg, the Netherlands
Function: caculate the minimum distance between all vertexes by using Floyd algerithm
Time: 8th,Jan,2017 
*/
#include<iostream>
#include<vector>
#define max 9999                       /////////should be much larger than any distance
using namespace std;
class Floyd{
	public:
	int num;
	vector<vector<int> > distance;   //////the metrix to store the distance between vertex
	vector<vector<int> > result;     /////  store the caculate result
	Floyd(int num);                  ///number of vertexes
	void addline(int point1,int point2,int weight);  ////////add lines between vertexes
	void show(void);
	void caculate(void);
};
////////the input num is the number of vertexes
Floyd::Floyd(int num){
	this->num=num;
	///////make the two matrix enough size to store data
    distance.resize(num);
    result.resize(num);
	for(int i=0;i<num;i++){
		distance[i].resize(num);
		result[i].resize(num);
	}
	//////////
	for(int i=0;i<num;i++)
	   for(int j=0;j<num;j++){
	   	distance[i][j]=max;
	   	result[i][j]=max;
	}
	for(int i=0;i<num;i++)
	distance[i][i]=0;
} 
/////add lines between vertex,weight is the distance, point1 and point2 are vertexes
void Floyd::addline(int point1,int point2,int weight){
	distance[point1][point2]=weight;
	distance[point2][point1]=weight;
}
/////begin to caculate the result
void Floyd::caculate(void){
	for(int i=0;i<num;i++)                ///////make result equal to the distance matrix
	   for(int j=0;j<num;j++){
	   	result[i][j]=distance[i][j];
	}
	for(int k=0;k<num;k++){
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				if(result[i][j]>result[k][j]+result[i][k]){
					result[i][j]=result[k][j]+result[i][k];
					result[j][i]=result[k][j]+result[i][k];
				}
			}
		}
	}
}
/////show the result
void Floyd::show(void){
	cout<<"input:"<<endl;
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			cout<<distance[i][j]<<"\t";
		}
	    cout<<endl;
	}
	cout<<"result:"<<endl;
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			cout<<result[i][j]<<"\t";
		}
	    cout<<endl;
	}
}

int main(void){
	Floyd mygraph(5);
	mygraph.addline(0,1,10);
	mygraph.addline(0,4,100);
	mygraph.addline(0,3,30);
	mygraph.addline(1,2,50);
	mygraph.addline(2,4,10);
	mygraph.addline(3,4,60);
	mygraph.addline(2,3,20);
	mygraph.caculate();
	mygraph.show();
	return 0;
} 
