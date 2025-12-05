#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>


class Solve {
public:
	// std::string Final;
	//
	// Solve(std::vector<std::string>& Object) {
 //        int sum = 0;
	//     int RowCount = Object.size();
 //        int ColumnCount = Object[0].size();
	//
 //        int NeighborRowOffsets[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
 //        int NeighborColOffsets[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
	//
 //        for (int Row = 0; Row < RowCount; Row++) {
 //            for (int Column = 0; Column < ColumnCount; Column++) {
 //                char Current = Object[Row][Column];
 //                if (Current != '@') continue;
 //                int AdjacentCount = 0; // if less than 4 increase sum
 //                for (int k = 0; k < 8; k++) {
 //                    int NeighborRow = Row + NeighborRowOffsets[k];
 //                    int NeighborColumn = Column + NeighborColOffsets[k];
 //                    Current = Object[NeighborRow][NeighborColumn];
 //                    if (NeighborRow >= 0 && NeighborRow < RowCount
 //                            && NeighborColumn >= 0 && NeighborColumn < ColumnCount) {
 //                              if (Current == '@') AdjacentCount++;  
 //                    }
	//
 //                }
 //            if (AdjacentCount < 4) sum++;
 //            }
 //        }
	//
 //        Final = std::to_string(sum);
	// }
        
        std::string Final;

        int NeighborRowOffsets[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int NeighborColOffsets[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
 
    Solve(std::vector<std::string>& Object) {
        int sum = 0;
        while (true) {
	    int RowCount = Object.size();
        int ColumnCount = Object[0].size();

       std::vector<std::pair<int,int>> RollsToRemove;
        for (int Row = 0; Row < RowCount; Row++) {
            for (int Column = 0; Column < ColumnCount; Column++) {
                char Current = Object[Row][Column];
                if (Current != '@') continue;
                int AdjacentCount = 0; // if less than 4 increase sum
                for (int k = 0; k < 8; k++) {
                    int NeighborRow = Row + NeighborRowOffsets[k];
                    int NeighborColumn = Column + NeighborColOffsets[k];
                    if (NeighborRow < 0 || NeighborRow >= RowCount) continue;
                    if (NeighborColumn < 0 || NeighborColumn >= ColumnCount) continue;
                    char Neighbor = Object[NeighborRow][NeighborColumn];
                    if (Neighbor == '@') AdjacentCount++;  
                }
                if (AdjacentCount < 4) RollsToRemove.emplace_back(Row, Column);
            }
        }
        if (RollsToRemove.empty()) break;

        for (auto& Position : RollsToRemove) {
            Object[Position.first][Position.second] = '.';
        }

        sum += RollsToRemove.size();
  
        }
       Final = std::to_string(sum);
    }     
};	

