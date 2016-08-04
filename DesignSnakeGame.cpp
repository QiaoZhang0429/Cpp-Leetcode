class SnakeGame {//queue
private:
	int width;
	int height;
	int score;
	int foodIndex;
	vector<pair<int, int>> food;
	deque<pair<int, int>> position;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
    	this.score = 0;
    	this.width = width;
    	this.height = height;
    	this.food = food;
    	this.foodIndex = 0;
    	position.push_back({0,0});
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
    	pair<int, int> head = position.front();
    	if(direction == "U")
    		head.first--;
    	if(direction == "L")
    		head.second--;
    	if(direction == "D")
    		head.first++;
    	if(direction == "R")
    		head.second++;
    	if(position.find(head) != position.end() || head.first < 0 || head.first >= height || head.second < 0 || head.second >= width)
    		return -1;
    	position.push_front(head);
    	if(foodIndex < food.size() && food[foodIndex] == head){
    		score++;
    		foodIndex++;
    	}
    	else
    		position.pop_back();
    	return score;
    }
};