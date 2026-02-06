#include "catch.hpp"
#include<iostream>
#include "ranges"

TEST_CASE("AAA", "BBB"){
    const std::string input = R"(..@@.@@@@.
@@@.@.@.@@
@@@@@.@.@@
@.@@@@..@.
@@.@@@@.@@
.@@@@@@@.@
.@.@.@.@@@
@.@@@.@@@@
.@@@@@@@@.
@.@.@@@.@.)";


    auto grid = input | std::views::split('\n') | std::ranges::to<std::vector<std::string>>();
    auto grid_copy = grid;

    int rows = grid.size();
    int cols = grid[0].size();

    int total_count = 0;

    for (int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){

            int count=0;

            char symbol = grid[i][j];

            if (symbol != '@'){
                continue;
            }
            // top left
            if (grid[i-1][j-1] == '@') count ++;
            // top middle
            if (grid[i-1][j] == '@') count ++;
            // top right
            if (grid[i-1][j+1] == '@') count ++;
            // middle left
            if (grid[i][j-1] == '@') count ++;
            // middle right
            if (grid[i][j+1] == '@') count ++;
            // down left
            if (grid[i+1][j-1] == '@') count ++;
            // down middle
            if (grid[i+1][j] == '@') count ++;
            // down right
            if (grid[i+1][j+1] == '@') count ++;
            
            if (count > 4){
                total_count ++;
            }
        }
    }
        
    std::printf("Total count %d \n", total_count);


}