#include <iostream>
using namespace std;
#define N 4

int computeMaxPriceUtil( int weights[], int values[], int W, int currentWeight, int nrElement){
	int maxReturn= 0;
	
	if( W < currentWeight)
		return 0;

	for( int i=0;i<N; i++){
		
		int temp = computeMaxPriceUtil( weights, values, W, currentWeight + weights[i] , i);
		maxReturn = max( maxReturn, temp);
	}
	
	return maxReturn + values[nrElement];
};

int computeMaxPrice( int weights[], int values[], int W){
	int maxReturn= 0;
		
	if( W <= 0)
		return 0;

	for( int i=0;i<N; i++){
		
		int temp = computeMaxPriceUtil( weights, values, W, 0 + weights[i], i);
		maxReturn = max(maxReturn, temp);
	}

	return maxReturn;
}

int main(){
	int weights[N] = { 3, 7, 4, 2};
	int values[N]  = { 2, 7, 2, 1};
	int W = 20;

	cout<< computeMaxPrice( weights, values, W);
	return 0;
}
