/*
Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not 
familiar with the game.
The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
You are given a list of food’s positions in row-column order. When a snake eats the food, its length and the game’s score 
both increase by 1.
Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten 
by the snake.
When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake. 
*/

#include <bits/stdc++.h>
using namespace std;

class SnakeGame {
    private:
        queue<pair<int, int>> q;
        vector<vector<int>> vis;
        vector<vector<int>> food;
        int foodInd;
        int currRow;
        int currCol;
        int width;
        int height;
        int score;

    public:
        SnakeGame(int width, int height, vector<vector<int>> &food) {
            vis.resize(width, vector<int>(height, false));
            this -> currRow = 0;
            this -> currCol = 0;
            this -> foodInd = 0;
            this -> food = food;
            this -> width = width;
            this -> height = height;
            this -> score = 0;
            q.push({currRow, currCol});
            vis[currRow][currCol] = true;
        }

    int move(string direction) {
        if(score == -1) {
            currRow = 0;
            currCol = 0;
            score = 0;
        }
        if(direction == "R") currCol++;
        if(direction == "L") currCol--;
        if(direction == "U") currRow--;
        if(direction == "D") currRow++;
        
        //Check if it touches the wall
        if(currCol < 0 || currCol >= width || currRow < 0 || currRow >= height) {
            score = -1;
            return score;
        }

        //If he touch himself
        if(vis[currRow][currCol]) {
            score = -1;
            return score;
        }
        
        q.push({currRow, currCol});
        //if he ate any food
        if((foodInd < food.size()) && (currCol == food[foodInd][1] && currRow == food[foodInd][0])) {
            score++;
            foodInd++;
        }
        else {
            auto [x, y] = q.front();
            q.pop();
            
            vis[x][y] = false;
        }
        vis[currRow][currCol] = true;

        return score;
    }

};

int main() {
    int width = 3, height = 2;
    vector<vector<int>> food = {{1, 2}, {0, 1}};

    SnakeGame snake(width, height, food);
    cout << "snake.move(\"U\"): " << snake.move("U") << '\n';
    cout << "snake.move(\"D\"): " << snake.move("D") << '\n';
    cout << "snake.move(\"R\"): " << snake.move("R") << '\n';
    cout << "snake.move(\"U\"): " << snake.move("U") << '\n';
    cout << "snake.move(\"L\"): " << snake.move("L") << '\n';
    cout << "snake.move(\"U\"): " << snake.move("U") << '\n';
}