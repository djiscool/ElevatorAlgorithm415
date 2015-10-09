#include "ElevatorSimone.hpp"
using namespace std;
int[] ElevatorSimone::ElevatorAlgorithm(){


}
int[] ElevatorSimone::input(){
		  
    cout << "How many floors does the building have?: ";
    cin >> floors;
    cout << "Many elevators does the building have?: ";
    cin >> elevators;
    cout << endl;
   
    
   
    createBuilding();
    // print building
    for ( const auto &row : building )
    {
        for ( const auto &s : row ) cout << s << ' ';
        cout << endl;
    }
	}
	
	void ElevatorSimone::createBuilding ( ){
    int width = (5 * (elevators/2));
    if (width == 0)
        width = 5;
 
    for (int i = 0; i < floors; i++){
        if (i == 0){
            for (int z = 0; z < width; z++){
                temp.push_back('-');
            }
            building.push_back(temp);
            temp.clear();
        }
            for (int j = 0; j <= floors; j++){
                if (j == 0){
                    temp.push_back('|');
                    for (int y = 1; y < (width -1); y++){
                        temp.push_back(' ');
                    }
                    temp.push_back('|');
                    building.push_back(temp);
                    temp.clear();
                }
            }
        }
    for (int x = 0; x < elevators; x++)
        building[floors][(((width) / 2) - x)] = 'X';
}